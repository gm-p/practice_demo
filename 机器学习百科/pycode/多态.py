# -*- coding: utf-8 -*-
"""
Created on Fri Mar 22 16:31:11 2019

@author: asus
"""

'''
方法重写：子类继承弗雷，会继承父类所有的方法，当父类的方法无法满足要求时，可在子类中定义一个同名的方法覆盖父类的方法，这叫做方法重写
当子类的实例调用该方法时，优先调用子类自身的方法，因为它被重写了
'''
class People:
    def speak(self):
        print("people is speaking")
        
class Student(People):
    def speak(self):   # 方法重写
        print("student is speaking")
        
class Teacher(People):
    pass

s = Student()
s.speak()

t = Teacher()
t.speak()

# 多态特性：多态意味着变量并不知道引用对象是什么，根据引用对象的不同表现不同的行为方式
class Animal:
    def eat(self):
        print("animal is eatting")
class Dog(Animal):
    def eat(self):
        print("dog is eatting")
class Cat(Animal):
    def eat(self):
        print("cat is eatting")
        
def eatting_double(animal):
    animal.eat()
    animal.eat()
    
animal = Animal()
dog = Dog()
cat = Cat()

eatting_double(animal)
eatting_double(dog)  # 接收的参数必须是拥有eat方法的对象，否则执行报错
eatting_double(cat)