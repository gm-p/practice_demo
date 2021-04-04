# -*- coding: utf-8 -*-
"""
Created on Mon Jan 28 22:19:13 2019
https://mp.weixin.qq.com/s?__biz=Mzg5NzAxMDgwNg==&mid=2247484006&idx=1&sn=1d0b49c0200e901915a99d29f0dadc79&chksm=c0791f7ff70e966929ed3a9b1358beb3b31a1106084f4332176476eafebf3a407fff2150d5b3&scene=21#wechat_redirect
@author: guangming.pan
"""

# 1.1列表转为矩阵
import numpy as np


array = np.array([
        [1, 3, 5],
        [4, 6, 9]
        ])
print(array)
# 1.2维度
print('number of dim:', array.ndim)
# 1.3行数和列数
print('shape:', array.shape)
#1.4元素个数
print('size:', array.size)

#2 Numpy创建array
# 2.1 一维array创建
a = np.array([2, 23, 4], dtype=np.int32) # np.int默认为int32
print(a)
print(a.dtype)
# 2.2 多维array创建
a = np.array([[2, 3, 4],
              [3, 4, 5]])
print(a) # 生成2行3列的矩阵
# 2.3创建全零数组
a = np.zeros((3, 4))
print(a) # 生成3行4列的全零矩阵
# 2.4创建全一数组
a = np.ones((3, 4), dtype=np.int)
print(a)
# 2.5创建全空数组
a = np.empty((3, 4))  # 每个值都是接近于0的值
print(a)
# 2.6 创建连续数组
a = np.arange(10, 21, 2)  # 10-20的数据，步长为2
print(a)
# 2.7 reshape操作
b = a.reshape((2, 3))
print(b)
# 2.8 创建连续型数据
a = np.linspace(1, 10, 20)  # 开始端1，结束端10，且分割成20个数据，生成线段
print(a)
# 2.9 linspace的reshape操作
b = a.reshape((5, 4))
print(b)

#3.Numpy的基本运算
# 3.1 一维矩阵运算
a = np.array([10, 20, 30, 40])
b = np.arange(4)
print(a, b)
c = a - b
print(c)
print(a*b)  #若用a.dot(b),则为各维之和
# 在Numpy中，想要求出矩阵中各个元素的乘方需要依赖双星符号**
c = b**2
print(c)
c = np.sin(a)
print(c)
print(b < 2)
a = np.array([1, 1, 4, 3])
b = np.arange(4)
print(a == b)
# 3.2 多维矩阵运算
a = np.array([[1, 1], [0, 1]])
b = np.arange(4).reshape((2, 2))
print(a)
print(b)
# 多维度矩阵乘法
c = a.dot(b)  #第一种乘法
print(c)
c = np.dot(a, b) # 第二种乘法
print(c)
# 多维矩阵乘法不能直接使用'*'号
a = np.random.random((2, 4))
print(a)
print(np.sum(a))
print(np.min(a))
print(np.max(a))

print("sum = ", np.sum(a, axis=1))
print("min = ", np.min(a, axis=0))
print("max = ", np.max(a, axis=1))
'''
如果你需要对行或列进行查找，就需要对axis赋值
axis = 0,将会以列作为查找单元
axis = 1,将会以行作为查找单元
'''

# 3.3 基本计算
A = np.arange(2, 14).reshape((3, 4))
print(A)

# 最小元素索引
print(np.argmin(A))
# 最大元素索引
print(np.argmax(A))
# 求整个矩阵的均值
print(np.mean(A)) 
print(np.average(A))
print(np.median(A))
# 累加
print(np.cumsum(A))
print(A.mean())
# 中位数A))
# 累差运算
B = np.array([[3, 5, 9], [4, 8, 10]])
print(np.diff(B))
C = np.array([[0, 5, 9], [4, 0, 10]])
print(np.nonzero(B)) # 将所有非零元素的行和列坐标分开，重构成两个分别关于行和列的矩阵
print(np.nonzero(C))
# 仿照列表排序
A = np.arange(14, 2, -1).reshape((3, 4)) # -1表示反向递减一个步长
print(A)
print(np.sort(A))  # 只对每行进行递增排序
print(np.transpose(A)) # 矩阵转置
print(A.T)  # 矩阵转置
print(A)
print(np.clip(A, 5, 9))
'''
clip(Array, Array_min, Array_max) 若Array_min < X < Array_max 则保持原数不变，
否则，若X < Array_min, 则 X = Array_min
     若X > Array_max, 则 X = Array_max
'''

# 4.Numpy索引与切片
A = np.arange(3, 15)
print(A)
print(A[3])
B = A.reshape(3, 4)
print(B)
print(B[2])
print(B[0][2])
print(B[0, 2])
# list 切片
print(B[1, 1:3]) 

for row in B:
    print(row)
    
# 打印列，则进行转置即可
for column in B.T:
    print(column)
    
# 多维转一维
A = np.arange(3, 15).reshape((3, 4))
print(A)
print(A.flatten())
# flat是一个迭代器，本身是一个Object属性
for item in A.flat:
    print(item)
    
# Numpy array合并
# 5.1数组合并
A = np.array([1, 1, 1])
B = np.array([2, 2, 2])
print(np.vstack((A, B)))  # vertical stack 上下合并
C = np.vstack((A, B))
print(C)
print(A.shape, B.shape, C.shape)
D = np.hstack((A, B)) # horizontal stack左右合并
print(D)
print(A.shape, B.shape, D.shape)
# 5.2 数组转置为矩阵
print(A[np.newaxis, :])
print(A[np.newaxis, :].shape)
print(A[:, np.newaxis])

# 5.3多个矩阵合并
# concatenate的第一个例子
print("--------------")
print(A[:, np.newaxis].shape)
A = A[:, np.newaxis]  # 数组转为矩阵
B = B[:, np.newaxis]  # 数组转为矩阵
C = np.concatenate((A, B, B, A), axis=0)  # axis=0纵向合并
print(C)

C = np.concatenate((A, B), axis=1) # axis=1横向合并
print(C)

# concatenate的第二个例子
a = np.arange(8).reshape(2, 4)
b = np.arange(8).reshape(2, 4)
print(a)
print(b)
c = np.concatenate((a, b), axis=0) # axis=0多个矩阵纵向合并
print(c)
c = np.concatenate((a, b), axis=1) # axis=1多个矩阵横向合并
print(c)
 
# 6. Numpy array分割
#6.1 构造3行4列矩阵
A = np.arange(12).reshape((3, 4))
print(A)
#6.2 等量分割
print(np.split(A, 2, axis=1)) #纵向分割同横向合并的axis
print(np.split(A, 3, axis=0)) #横向分割同纵向合并axis
#6.3 不等量分割
print(np.array_split(A, 3, axis=1))
#6.4 其他分割方式
print(np.vsplit(A, 3)) #横向分割，等价于pirnt(np.split(A, 3, axis=0))
print(np.hsplit(A, 2)) #纵向分割，等价于print(np.split(A, 2, axis=1))

# 7.Numpy copy 与 =
# 7.1 =赋值方式会带来关联性
a = np.arange(4)
print(a)

b = a
c = a
d = b
a[0] = 11
print(a)
print(b)
print(c)
print(d)
print(b is a)
print(c is a)
print(d is a)

d[1:3] = [22, 33]
print(a)
print(b)
print(c)

# 7.2 copy()赋值方式没有关联性
a = np.arange(4)
print(a)
b = a.copy()
print(b)
a[3] = 44
print(a)
print(b)

# 8.广播机制
a = np.array([[0, 0, 0],
              [10, 10, 10],
              [20, 20, 20],
              [30, 30, 30]])
b = np.array([0, 1, 2])
print(a + b)

b = np.tile([0, 1, 2], (4, 1)) # 对[0,1,2]行重复3次，列重复1次
print(a + b)

# 9.常用函数
# 9.1 np.bincount()
x = np.array([1, 2, 3, 3, 0, 1, 4])
print(np.bincount(x))  #统计索引出现次数

w = np.array([0.3, 0.5, 0.7, 0.6, 0.1, -0.9, 1])
print(np.bincount(x, weights=w))

# minlength当所给的bin数量多于实际从x中得到的bin数量后，后面没有访问到的设置为0即可
print(np.bincount(x, minlength=7))

# 9.2 np.argmax()
# 函数原型为：numpy.argmax(a, axis=None, out=None)
# 功能：返回沿轴axis最大值的索引
x = [[1, 3, 3],
     [7, 5, 2]]
print(np.argmax(x))

# axis=0表示按列操作，对比当前列，找出最大值的索引
x = [[1, 3, 3],
     [7, 5, 2]]
print(np.argmax(x, axis=0))
# axis=1 表示按行操作，对比当前行，找出最大值的索引
print(np.argmax(x, axis=1))

# 最大元素重复返回第一个
x = np.array([1, 3, 2, 3, 0, 1, 0])
print(x.argmax())

x = np.array([1, 2, 3, 3, 0, 1, 4])
print(np.argmax(np.bincount(x)))

# 9.4求取精度
# 取指定位置的精度
print(np.around([-0.6, 1.2798, 2.357, 9.67, 13], decimals=0)) # 负数进位取绝对值大的

print(np.around([1.2798, 2.357, 9.67, 13], decimals=1))

print(np.around([1.2798, 2.357, 9.67, 13], decimals=2))

print(np.around([1, 2, 5, 6, 56], decimals=-1))  # -1表示看一位数进位

print(np.around([1, 2, 5, 50, 56, 190], decimals=-2))

# 计算沿指定轴第N维的离散差值
x = np.arange(1, 16).reshape((3, 5))
print(x)
print(np.diff(x, axis=1)) # 默认axis=1
print(np.diff(x, axis=0))

# 取整
print(np.floor([-0.6, -1.4, -0.1, -1.8, 0, 1.4, 1.7]))  # 负数取整，跟around一样，向左

# 取上限
print(np.ceil([1.2, 1.5, 1.8, 2.1, 2.0, -0.5, -0.6, -0.3]))

# 查找
x = np.array([[1, 0],   # 利用np.where实现小于0的值用0填充，大于0的数不变
              [2, -2],
              [-2, 1]])
print(x)
print(np.where(x>0, x, 0))





