# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 16:03:04 2019

@author: asus
"""

'''
class ClassName:
    类的属性定义
    类的方法

类的属性：   
    基础属性的定义与定义变量相同：var = ""
    私有属性：以双下划线开头，如__privateattr = 0,表示其只能在类内部以self.的方式访问,类的实例无法访问
类的方法：
    类方法必须包含self参数，且是第一个参数，self代表是类的实例
    def function(self):
        方法体
    私有方法：以双下划线开头，如def __func(self): 表示其只能在类的内部以self.的方式访问，类的实例无法访问
    一般都会为类定义一个构造方法__init__(self)同样第一个采纳数必须是self，在创建类的实例时，会自动调用该构造方法
    def __init__(self, name):
        self.name = name
类的实例：
    object = ClassName(argu1, argu2, ...)
'''

class Rectangel:
    # 定义类的属性
    width = 0
    height = 0
    
    #定义类的私有属性
    __color = ""
    
    # 定义类的构造函数
    def __init__(self, width, height, color):
        self.width = width
        self.height = height
        self.__color = color
    #定义类的私有方法，获取矩形面积
    def __getArea(self):
        return self.width * self.height
    
    #定义类的方法。打印此矩形的 长宽面积
    #类内部可调用类的私有属性私有方法
    def printme(self):
        print("width = %d, height = %d, area = %d, color = %s" % (self.width, self.height, self.__getArea(), self.__color))
        
#创建类的实例，自动调用__init__()构造方法
R = Rectangel(3, 4, "blue")

#访问类的实例的属性
print("width = ", R.width)
#访问类的属性
R.printme()

#访问实例的私有属性和私有方法。这里会报错，因为实例无法访问类的私有属性和私有方法
#print("color = %s, Area = %d" % (R.__color, R.__getArea()))