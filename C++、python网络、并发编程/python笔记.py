# 魔法函数
class Company(object):
    def __init__(self, employee_list):
        self.employee = employee_list

    def __getitem__(self, item):
        return self.employee[item]

company = Company(['tom', 'bob', 'jane'])

for em in company:
    print(em)

company1 = company[:2]   # 切片
for em in company1:
    print(em)

import pandas as pd
# 突破private访问限制
class User:
    def __init__(self, birthday):
        self.__birthday = birthday

    def get_age(self):
        return 2020 - self.__birthday.year

date = pd.to_datetime('2019-6-1')
user = User(date)
print(user._User__birthday)  # private只是改变了名字还是可以访问
print(user.get_age())

# python自身机制
class Student:
    def __init__(self, scool_name):
        self.scool_name = scool_name

user = Student('慕课网')
# 通过__dict__查询属性
print(user.__dict__)
user.__dict__['school_addr'] = '北京市'
print(user.school_addr)
print(Student.__dict__)
a = [1, 2]
print(dir(a))

# 上下文管理器协议
class Sample:
    def __enter__(self):
        print('enter')
        # 获取资源
        return self
    def __exit__(self, exc_type, exc_val, exc_tb):
        # 释放资源
        print('exit')
    def do_something(self):
        print('doing something')

with Sample() as sample:
    sample.do_something()


# bisect用来处理已排序的序列，用来维持已排序的序列，升序
# 二分查找
import bisect
from collections import deque

inter_list = deque()
bisect.insort(inter_list, 3)
bisect.insort(inter_list, 2)
bisect.insort(inter_list, 5)
bisect.insort(inter_list, 1)
bisect.insort(inter_list, 6)

print(bisect.bisect_left(inter_list, 3))
print(inter_list)


# array 数组, deque
# array和list的一个重要区别，array只能存放指定的数据类型
import array
my_array = array.array('i')
my_array.append(1)
# my_array.append('abc')  # 出错


# 列表生成式
odd_list = [i for i in range(21) if i % 2 == 1]

# 逻辑更复杂的情况
def handle_item(item):
    return item * item
odd_list = [handle_item(i) for i in range(21) if i % 2 == 1]
# 列表生成式性能高于列表操作
print(type(odd_list))
print(odd_list)

# 生成器表达式
odd_gen = (i for i in range(21) if i % 2 == 1)
print(type(odd_gen))
odd_list = list(odd_gen)

print(type(odd_list))
print(odd_list)

# 字典推导式
my_dict = {"bobby1": 22, "bobby2": 23, "immoc.com": 5}
reverserd_dict = {value: key for key, value in my_dict.items()}
print(reverserd_dict)

# 集合推导式
# my_set = set(my_dict.keys())
my_set = {key for key, value in my_dict.items()}
print(type(my_set))
print(my_set)


# 浅拷贝和深拷贝
a = {"bobby1": {"company": "imooc"},
     "bobby2": {"company": "imooc2"}}
# a.clear()
# copy,返回浅拷贝
new_dict = a.copy()
new_dict['bobby1']['company'] = 'imooc3'
print(a)
print(new_dict)

import copy

new_dict = copy.deepcopy(a)  # 深拷贝
new_dict['bobby1']['company'] = 'imooc4'
print(a)
print(new_dict)


# dict查找性能远远大于list
# 在list中随着list数据的增大，查找时间会增大
# 在dict中查找元素不会随着dict的增大而增大
# 1. dict的key或者set的值必须是可hash的
#    不可变对象 都是可hash的，str，fronzenset，tuple，自己实现的类__hash__
# 2. dict的内存花销大，但是查找速度快，自定义的对象或者python内部的对象都是dict包装的
# 3. dict的存储顺序和元素添加顺序有关
# 4. 添加数据有可能改变已有数据的顺序