# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 16:21:21 2019

@author: asus
"""

'''
python 支持类的继承，同时支持多继承
class DerivedClass(BaseClass1, BaseClass2, ..., BaseClassN):
    类的属性
    类的方法
当子类调用自身没有定义的方法，也没有指定具体的基类名称时，Python会从左到右一次查找基类中是否包含该方法，
直到找到就停止，否则报错
'''

# 定义Animal类
class Animal:
    def eat(self):
        print("animal is eatting")

class People:
    def eat(self):
        print("people is eatting")
    def speak(self):
        print("people is speaking")

class Student(People, Animal):
    pass

class Teacher(Animal, People):
    pass

s = Student()
s.eat()  # People类有speak方法
s.speak()

t = Teacher()
t.eat()  
t.speak() # 先搜索Animal类没有speak方法，继续搜People类找到哦啊speak方法