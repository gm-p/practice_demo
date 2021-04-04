import pandas as pd
from sklearn import preprocessing
from sklearn.ensemble import RandomForestRegressor
from sklearn.datasets import load_boston

# 加载数据
boston_house = load_boston()

boston_feature_name = boston_house.feature_names
boston_features = boston_house.data
boston_target = boston_house.target

print(boston_feature_name)
print(boston_house.DESCR)
#print(boston_house)

print(boston_features[:5, :])
print(boston_target)

# 构建模型
rf = RandomForestRegressor(n_estimators=15)
rf = rf.fit(boston_features, boston_target)

print(rf)

print(rf.predict(boston_features))

from sklearn import tree

dt = tree.DecisionTreeRegressor()
dt.fit(boston_features, boston_target)
print(dt.predict(boston_features))