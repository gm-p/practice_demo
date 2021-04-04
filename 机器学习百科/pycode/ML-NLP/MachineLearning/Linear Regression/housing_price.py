import os
import numpy as np
import pandas as pd

np.random.seed(36)

import matplotlib
import seaborn
import matplotlib.pyplot as plt

from sklearn import datasets


housing = pd.read_csv('kc_train.csv', header=None)
target = housing.iloc[:, 1]
housing.drop([1], inplace=True, axis=1)
housing.columns = range(housing.shape[1])
print(housing.head())
print(target.head())

t = pd.read_csv('kc_test.csv', header=None)

# 数据预处理
housing.info()

# 特征缩放
from sklearn.preprocessing import MinMaxScaler
minmax_scaler = MinMaxScaler()
minmax_scaler.fit(housing)
scaler_housing = minmax_scaler.transform(housing)
scaler_housing = pd.DataFrame(scaler_housing, columns=housing.columns)

mm = MinMaxScaler()
mm.fit(t)
scaler_t = mm.transform(t)
scaler_t = pd.DataFrame(scaler_t, columns=t.columns)

# 选择基于梯度下降的线性回归模型
from sklearn.linear_model import LinearRegression
lr_reg = LinearRegression()
lr_reg.fit(scaler_housing, target)


# 使用均方误差用于评估模型好坏
from sklearn.metrics import mean_squared_error
preds = lr_reg.predict(scaler_housing)   # 输入数据进行预测得到结果
mse = mean_squared_error(preds, target)  # 使用均方误差评价模型好坏，可以输出mse进行查看评价值

# 绘图进行比较
plt.figure(figsize=(10, 7))  # 画布大小
num = 100
x = np.arange(1, num+1)   # 取100个点进行比较
plt.plot(x, target[:num], label='target')  # 目标取值
plt.plot(x, preds[:num], label='preds')  # 预测取值
plt.legend(loc='upper right')   # 线条显示位置
plt.show()

# 输出测试数据预测结果
result = lr_reg.predict(scaler_t)
df_result = pd.DataFrame(result)
df_result.to_csv('result.csv', index=False, header=False)