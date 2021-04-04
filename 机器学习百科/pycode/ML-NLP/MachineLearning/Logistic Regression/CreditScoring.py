import pandas as pd 
pd.set_option('display.max_columns', 500)
import zipfile
with zipfile.ZipFile('KaggleCredit2.csv.zip', 'r') as z:
    f = z.open('KaggleCredit2.csv')
    data = pd.read_csv(f, index_col=0)
print(data.head())
print(data.shape)
print(data.isnull().sum(axis=0))

data.dropna(inplace=True)  # 去掉空数据
print(data.shape)

y = data['SeriousDlqin2yrs']
X = data.drop('SeriousDlqin2yrs', axis=1)

print(y.mean())


# 把数据集分成训练集和测试集
from sklearn import model_selection
x_train, x_test, y_train, y_test = model_selection.train_test_split(X, y, test_size=0.2)
print(x_train.shape, y_train.shape)
print(x_test.shape, y_test.shape)

# 使用logistic regression进行分类
from sklearn.linear_model import LogisticRegression
lr = LogisticRegression(multi_class='ovr', solver='sag', class_weight='balanced')
lr.fit(x_train, y_train)
score = lr.score(x_train, y_train)
print(score)  

# 在测试集上进行测试
from sklearn.metrics import accuracy_score
train_score = accuracy_score(y_train, lr.predict(x_train))
test_score = lr.score(x_test, y_test)
print('训练集准确率:', train_score)
print('测试集准确率:', test_score)


# 召回率
from sklearn.metrics import recall_score
train_recall = recall_score(y_train, lr.predict(x_train), average='macro')
test_recall = recall_score(y_test, lr.predict(x_test), average='macro')
print('训练集召回率:', train_recall)
print('测试集召回率:', test_recall)

# 银行通常会有更严格的要求，因为fraud带来的后果通常比较严重，一般我们会调整模型的标准。
#比如在logistic regression当中，一般我们的概率判定边界为0.5，但是我们可以把阈值设定低一些，来提高模型的“敏感度”，
#试试看把阈值设定为0.3，再看看这时的评估指标(主要是准确率和召回率)。
#tips:sklearn的很多分类模型，predict_prob可以拿到预估的概率，可以根据它和设定的阈值大小去判断最终结果(分类类别)
import numpy as np
y_pro = lr.predict_proba(x_test)  # 获取预测概率值
y_prd2 = [list(p >= 0.3).index(1) for i, p in enumerate(y_pro)]  # 设定0.3阈值，把大于0.3的看成1分类
train_score = accuracy_score(y_test, y_prd2)
print(train_score)
 
 