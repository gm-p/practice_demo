# -*- coding: utf-8 -*-
"""
Created on Thu Jan 31 23:26:42 2019

@author: guangming.pan
"""

import pandas as pd
import numpy as np

# Series
s = pd.Series([1, 3, 6, np.nan, 44, 1])
print(s)
#默认index从0开始，如果想要按照自己的索引设置，则修改index参数，如index=[3, 4, 3, 7, 8, 9]

# DataFrame
dates = pd.date_range('2018-08-19', periods=6)
# dates = pd.date_range('2018-08-19', '2018-08-24') # 起始，结束  与上述等价
'''
numpy.random.randn(d0, d1, ..., dn)是从标准正态分布中返回一个或多个样本值
numpy.random.rand(d0, d1, ..., dn)的随机样本位于[0,1)中
(6, 4)表示6行4列的数据
'''
df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=['a', 'b', 'c', 'd'])
print(df)
# DataFrame既有行索引也有列索引，它可以被看做由Series组成的大字典
print(df['b'])

# 未指定行标签和列标签的数据
df1 = pd.DataFrame(np.arange(12).reshape(3, 4))
print(df1)
#另一种方式
df2 = pd.DataFrame({
        'A': [1, 2, 3, 4],
        'B': pd.Timestamp('20180819'),
        'C': pd.Series([1, 6, 9, 10], dtype='float32'),
        'D': np.array([3] * 4, dtype='int32'),
        'E': pd.Categorical(['test', 'train', 'test', 'train']),
        'F': 'foo'
})
print(df2)
print(df2.dtypes)

print(df2.index)
print(df2.columns)
print(df2.values)
print(df2.describe())  #数据总结

print(df2.T)  # 翻转数据
print(np.transpose(df2))  #等价于上述操作

'''
axis = 1表示行
axis = 0表示列
默认ascending=True表示升序，ascending=False表示降序
'''
print(df2.sort_index(axis=1, ascending=True))
print(df2.sort_index(axis=1, ascending=False))

# 表示按列降序与按列升序
print(df2.sort_index(axis=0, ascending=False))
print(df2.sort_index(axis=0, ascending=True))

# 对特定列数值排序
# 表示对C列降序排列
print(df2.sort_values(by='C', ascending=False))

# 3.pandas选择数据
# 3.1实战筛选
dates = pd.date_range('20180819', periods=6)
df = pd.DataFrame(np.arange(24).reshape((6, 4)), index=dates, columns=['A', 'B', 'C', 'D'])
print(df)
#检索A列
print(df['A'])
print(df.A)

#选择跨越多行或多列
#选择前3行
print(df[0:3])
print(df['2018-08-19':'2018-08-21'])

# 根据标签选择数据
# 获取特征行或列
# 指定行数据
print(df.loc['20180819'])

# 指定列
#两种方式
print(df.loc[:, 'A':'B'])
print(df.loc[:, ['A', 'B']])

# 行与列同时检查
print(df.loc['20180819', ['A', 'B']])

# 根据序列iloc获取特定位置的值
print(df.iloc[3, 1])
print(df.iloc[3:5, 1:3]) # 不包含末尾5或3，同列表切片

# 跨行操作
print(df.iloc[[1, 3, 5], 1:3])

