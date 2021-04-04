# coding=utf-8

'''
 匿名函数:python用lambda来创建匿名函数
 lambda arg1, arg2, ..., argn: expression
'''
def multiply(x, y):
    return x*y
func = lambda x, y : x*y
print(func(3, 4))

func = lambda x, y : x+y
print(func(3, 4))
f = lambda x : x*x
print(f(3))

'''
 map():接收两个参数，一个是函数f，一个是iterator，map在iterable的每个元素上一次执行函数f，并把结果作为新的iterator返回
'''
def f(x):
    return x*x
result = map(f, [1, 2, 3])
for var in result:
    print(var)
l = [x*x for x in range(1, 4)]
print(l)

result = map((lambda x : x+5), range(1, 4))
for var in result:
    print(var)

'''
 reduce():接收两个参数，一个是函数f，一个是iterator，其中函数f必须接收两个参数。
          reduce在iterator的第一个元素上执行函数f得到结果res，然后将结果res继续与第三个元素作为函数f的两个参数继续执行函数f，
          直到遍历完成
'''
from functools import reduce
def f(x, y):
    return x * y
result = reduce(f, range(1, 4))  # 1*2*3
print(result)

result = reduce((lambda x, y : x-y), [8, 3, 1]) # 8-3-1
print(result)

'''
 filter():用于过滤序列
 接收两个参数：一个函数和一个序列，将函数作用在序列的每一个元素上，根据函数的返回值True或False，决定是否舍弃该元素
'''
def is_even(x):
    return x % 2 == 0
l = filter(is_even, [0, 1, 2, 3, 4, 5])
print(l)   # 返回迭代器
for var in l:
    print(var)

# 给定一系列字符串元组，筛选出包含Python的所有字符串
str_tuple = ("hipython", "pyth", "lovepython", "PYTHON", "XMU")
result = filter((lambda x:x.find("python")!=-1), str_tuple)
for str in result:
    print(str)
    
# 给定一系列字符串元组，刷新出长度为5的字符串
str_list = ["abcde", "12345", "python", "xmu", "hello"]
result = filter((lambda x : len(x) == 5), str_list)
for str in result:
    print(str)