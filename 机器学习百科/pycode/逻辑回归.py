# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 16:50:12 2019

@author: asus
"""

import numpy as np
import pandas as pd
import statsmodels.api as sm
import pylab as pl

df = pd.read_csv("./binary.csv")
print(df.head())
'''
   admit  gre   gpa  rank
0      0  380  3.61     3
1      1  660  3.67     3
2      1  800  4.00     1
3      1  640  3.19     4
4      0  520  2.93     4
'''

# 重命名‘rank’列，因为dataframe中有个方法名也为‘rank’
df.columns = ["admit", "gre", "gpa", "prestige"]
print(df.columns)
print(df.describe())
'''
            admit         gre         gpa   prestige
count  400.000000  400.000000  400.000000  400.00000
mean     0.317500  587.700000    3.389900    2.48500
std      0.466087  115.516536    0.380567    0.94446
min      0.000000  220.000000    2.260000    1.00000
25%      0.000000  520.000000    3.130000    2.00000
50%      0.000000  580.000000    3.395000    2.00000
75%      1.000000  660.000000    3.670000    3.00000
max      1.000000  800.000000    4.000000    4.00000
'''
# 查看每一列的标准差
print(df.std())
'''
admit         0.466087
gre         115.516536
gpa           0.380567
prestige      0.944460
dtype: float64
'''

# 频率表，表示prestige与admit的值相应的数量关系
print(pd.crosstab(df['admit'], df['prestige'], rownames=['admit']))
'''
prestige   1   2   3   4
admit                   
0         28  97  93  55
1         33  54  28  12
'''
# plot all of the columns
df.hist()
pl.show()

# 将prestige设为虚拟变量
dummy_ranks = pd.get_dummies(df['prestige'], prefix='prestige')
print(dummy_ranks.head())
'''
   prestige_1  prestige_2  prestige_3  prestige_4
0           0           0           1           0
1           0           0           1           0
2           1           0           0           0
3           0           0           0           1
4           0           0           0           1
'''
# 为逻辑回归创建所需的data frame
# 除admit、gre、gpa外，加入了上面常见的虚拟变量(注意，引入的虚拟变量列数应为虚拟变量总列数减1，减去的1列作为基准)
cols_to_keep = ['admit', 'gre', 'gpa']
data = df[cols_to_keep].join(dummy_ranks.iloc[:, 1:])
print(data.head())
'''
   admit  gre   gpa  prestige_2  prestige_3  prestige_4
0      0  380  3.61           0           1           0
1      1  660  3.67           0           1           0
2      1  800  4.00           0           0           0
3      1  640  3.19           0           0           1
4      0  520  2.93           0           0           1
'''
# 需要自行添加逻辑回归所需的intercept变量
data['intercept'] = 1.0

# 指定作为训练变量的列，不含目标列'admit'
train_cols = data.columns[1:]
logit = sm.Logit(data['admit'], data[train_cols])
# 拟合模型
result = logit.fit()

# 构建预测集
# 与训练集相似，一般也是通过pd.read_csv()读入
# 在这里为了方便，我们将训练集拷贝一份作为预测集（不包含admit列）
import copy
combos = copy.deepcopy(data)

# 数据中的列要跟预测时用到的列一致
predict_cols = combos.columns[1:]
# 预测也要添加intercept变量
combos['intercept'] = 1.0
# 进行预测，并将预测评分存入predict列中
combos['predict'] = result.predict(combos[predict_cols])

# 预测完成后，predict的值是介于[0, 1]间的概率值
# 我们可以根据需要，提取预测结果
# 例如，假定predict > 0.5,则表示会被录取，在这边我们检验一下上述选取结果的精确度
total = 0
hit = 0
for value in combos.values:
    # 预测分数predict，是数据中最后一列
    predict = value[-1]
    # 实际录取结果
    admit = int(value[0])
    
    # 假定预测概率大于0.5则表示预测被录取
    if predict > 0.5:
        total += 1
        # 表示预测命中：
        if admit == 1:
            hit += 1
            
# 输出结果
print("Total: %d, Hit: %d, Precision: %.2f " % (total, hit, 100.0*hit/total))
# Total: 49, Hit: 30, Precision: 61.22 

# 查看数的要点
print(result.summary())
# 查看每个系数的置信区间
print(result.conf_int())
'''
                   0         1
gre         0.000120  0.004409
gpa         0.153684  1.454391
prestige_2 -1.295751 -0.055135
prestige_3 -2.016992 -0.663416
prestige_4 -2.370399 -0.732529
intercept  -6.224242 -1.755716
'''
# 输出odds ratio
print(np.exp(result.params))
'''
gre           1.002267
gpa           2.234545
prestige_2    0.508931
prestige_3    0.261792
prestige_4    0.211938
intercept     0.018500
'''
# odds ratios and 95% CI
params = result.params
conf = result.conf_int()
conf['OR'] = params
conf.columns = ['2.5%', '97.5%', 'OR']
print(np.exp(conf))
'''
                2.5%     97.5%        OR
gre         1.000120  1.004418  1.002267
gpa         1.166122  4.281877  2.234545
prestige_2  0.273692  0.946358  0.508931
prestige_3  0.133055  0.515089  0.261792
prestige_4  0.093443  0.480692  0.211938
intercept   0.001981  0.172783  0.018500
'''

# 根据最大、最小值生成gre，gpa均匀分布的10个数，而不是生成所有可能的值
gres = np.linspace(data['gre'].min(), data['gre'].max(), 10)
print(gres)
# [220.         284.44444444 348.88888889 413.33333333 477.77777778
# 542.22222222 606.66666667 671.11111111 735.55555556 800.        ]
gpas = np.linspace(data['gpa'].min(), data['gpa'].max(), 10)
print(gpas)
#[2.26       2.45333333 2.64666667 2.84       3.03333333 3.22666667
# 3.42       3.61333333 3.80666667 4.        ]

def cartesian(arrays, out=None):
    arrays = [np.asarray(x) for x in arrays]
    dtype = arrays[0].dtype
    
    n = np.prod([x.size for x in arrays])
    if out is None:
        out = np.zeros([n, len(arrays)], dtype=dtype)
        
    m = n // arrays[0].size
    out[:, 0] = np.repeat(arrays[0], m)
    if arrays[1:]:
        cartesian(arrays[1:], out=out[0:m, 1:])
        for j in range(1, arrays[0].size):
            out[j*m:(j+1)*m, 1:] = out[0:m, 1:]
    return out
    
# 枚举所有可能性
combos = pd.DataFrame(cartesian([gres, gpas, [1, 2, 3, 4], [1.]]))
# 重新创建哑变量
combos.columns = ['gre', 'gpa', 'prestige', 'intercept']
dummy_ranks = pd.get_dummies(combos['prestige'], prefix='prestige')
dummy_ranks.columns = ['prestige_1', 'prestige_2', 'prestige_3', 'prestige_4']

# 只保留用于预测的列
cols_to_keep = ['gre', 'gpa', 'prestige', 'intercept']
combos = combos[cols_to_keep].join(dummy_ranks.iloc[:, 1:])
#使用枚举的数据集来预测
combos['admit_pred'] = result.predict(combos[train_cols])
print(combos.head())

def isolate_and_plot(variable):
    grouped = pd.pivot_table(combos, values=['admit_pred'], index=[variable, 'prestige'], aggfunc=np.mean)
    print(grouped.head())
    
    colors = 'rbgyrbgy'
    for col in combos.prestige.unique():
        plt_data = grouped.iloc[grouped.index.get_level_values(1) == col]
        pl.plot(plt_data.index.get_level_values(0), plt_data['admit_pred'], color=colors[int(col)])
    
    pl.xlabel(variable)
    pl.ylabel("P(admit=1)")
    pl.legend(['1', '2', '3', '4'], loc='upper left', title='Prestige')
    pl.title("Prob(admit=1) isolating " + variable + " and prestige")
    pl.show()
    
isolate_and_plot('gre')
isolate_and_plot('gpa')