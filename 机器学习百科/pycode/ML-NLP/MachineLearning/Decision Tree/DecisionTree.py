import pandas as pd
from sklearn import preprocessing  # 引入用于数据预处理/特征工程的工具包
from sklearn import tree

adult_data = pd.read_csv('./DecisionTree.csv')

print(adult_data.head(5))

print(adult_data.info())

print(adult_data.shape)

print(adult_data.columns)

# 区分特征和目标列
feature_columns = ['workclass', 'education', 'marital-status', 'occupation',
       'relationship', 'race', 'gender', 'native-country']
label_column = ['income']

features = adult_data[feature_columns]
label = adult_data[label_column]

print(features.head(2))
print(label.head(2))


# 特征工程
features = pd.get_dummies(features)
print(features.head(2))


# 构建模型
# 初始化一个决策树分类器
clf = tree.DecisionTreeClassifier(criterion='entropy', max_depth=4)
# 用决策树分类器拟合数据
clf = clf.fit(features.values, label.values)
print(clf)

clf.predict(features.values)

# 可视化一下这棵决策树
import pydotplus
from IPython.display import display, Image

dot_data = tree.export_graphviz(clf,
                                out_file=None,
                                feature_names=features.columns,
                                class_names=['<=50k', '>50k'],
                                filled=True,
                                rounded=True)
graph = pydotplus.graph_from_dot_data(dot_data)
display(Image(graph.create_png()))

