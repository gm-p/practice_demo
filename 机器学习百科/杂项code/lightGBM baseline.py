# https://www.jianshu.com/p/757e01aebb2b

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from sklearn.externals import joblib
from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import f1_score
import lightgbm as lgb
import warnings
warnings.filterwarnings('ignore')


pd.set_option('display.max_columns', 500, 'display.width', 1000)   # 设置显示宽高
# data_train = pd.read_csv('train/train.csv')
data_train = pd.read_csv('train_3.csv')  # 训练集
data_test = pd.read_csv('test_3.csv')    # 测试集
# 对current_service映射编码，对要分类的label不是从0开始的一般操作
label2current_service = dict(zip(range(0, len(set(data_train['current_service']))),
                                 sorted(list(set(data_train['current_service'])))))
current_service2label = dict(zip(sorted(list(set(data_train['current_service']))),
                             range(0, len(set(data_train['current_service'])))))
data_train['current_service'] = data_train['current_service'].map(current_service2label)
# print(len(set(data_train['current_service'])))   # 15种类型
y = data_train.pop('current_service')
user_id = data_train.pop('user_id')
x_train = data_train
test_user_id = data_test.pop('user_id')
x_test = data_test
print(x_train.info())
X, y, X_test = x_train.values, y.values, x_test.values   # 转为np.array类型
n_splits = 5   # 分为5折
seed = 2333    # 随机种子
# lgb 参数
lgb_params = {
    'learning_rate': 0.05,
    'lambda_l1': 0.1,
    'lambda_l2': 0.2,
    'max_depth': 7,
    'num_levels': 120,
    'objective': 'multiclass',
    'num_class': 15,
    'verbose': -1,
    'feature_fraction': 0.8,
    'min_split_gain': 0.1,
    'boosting_type': 'gbdt',
    'subsample': 0.8,
    'min_data_in_leaf': 50,
    'colsample_bytree': 0.7,
    'colsample_bylevel': 0.7,
    'tree_method': 'exact'
}

# 采取k折模型方案
# 自定义F1评价函数
def f1_score_vail(pred, data_vail):
    labels = data_vail.get_label()
    pred = np.argmax(pred.reshape(15, -1), axis=0)   # lgb的predict输出各类型概率值
    score_vail = f1_score(y_true=labels, y_pred=pred, average='macro')
    return 'f1_score', score_vail, True


x_score = []     # 交叉验证各折的f1值
cv_pred = []     # 各折的预测值
skf = StratifiedKFold(n_splits=n_splits, random_state=seed, shuffle=True)
# 交叉验证
for index, (train_index, test_index) in enumerate(skf.split(X, y)):
    print(index)
    X_train, X_valid, y_train, y_valid = X[train_index], X[test_index], y[train_index], y[test_index]
    train_data = lgb.Dataset(X_train, label=y_train)   # 训练数据
    validation_data = lgb.Dataset(X_valid, label=y_valid)   # 验证数据
    clf = lgb.train(lgb_params, train_data, num_boost_round=150000, valid_sets=[validation_data],
                    early_stopping_rounds=100, feval=f1_score_vail, verbose_eval=1)   # 训练
    # clf = joblib.load('model/lgb_{}.m'.format(index))    # 保存模型
    # joblib.dump(clf, 'model/lgb_{}.m'.format(index))     # 加载模型
    x_pred = clf.predict(X_valid, num_iteration=clf.best_iteration)
    x_pred = [np.argmax(x) for x in x_pred]
    x_score.append(f1_score(y_valid, x_pred, average='macro'))  # 计算f1值
    y_test = clf.predict(X_test, num_iteration=clf.best_iteration)  # 预测
    y_test = [np.argmax(x) for x in y_test]
    if index == 0:
        cv_pred = np.array(y_test).reshape(-1, 1)
    else:
        cv_pred = np.hstack((cv_pred, np.array(y_test).reshape(-1, 1)))
    if index == 4:
        lgb.plot_importance(clf, figsize=(50, 50))   # 画出重要特征
        plt.title('Feature_importance')
        plt.show()

# 投票
submit = []
for line in cv_pred:
    submit.append(np.argmax(np.bincount(line)))
# 保存结果
df_test = pd.DataFrame()
df_test['id'] = list(test_user_id.unique())
df_test['predict'] = submit
df_test['predict'] = df_test['predict'].map(label2current_service)
df_test.to_csv('output/lgb4.csv', index=False)
print(x_score, np.mean(x_score))