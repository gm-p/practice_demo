Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 19:28:18) [MSC v.1600 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> type(len)
<class 'builtin_function_or_method'>
>>> type(dir)
<class 'builtin_function_or_method'>
>>> type(int)
<class 'type'>
>>> type(list)
<class 'type'>
>>> class C:
	pass

>>> type(C)
<class 'type'>
>>> int('123')
123
>>> a = int('123')
>>> b = int('456')
>>> a + b
579
>>> class New_int(int):
	def __add__(self, other)
	
SyntaxError: invalid syntax
>>> class New_int(int):
	def __add__(self, other):
		return int.__sub__(self,other)
	def __sub__(self,other):
		return int.__add__(self,other)

	
>>> a = New_int(3)
>>> b = New_int(3)
>>> a+b
0
>>> a - b
6
>>> class Try_int(int):
	def __add__(self, other):
		return self + other
	def __sub__(self, other):
		return self - other

	
>>> a = Try_int(3)
>>> b = Try_int(5)
>>> a+b
Traceback (most recent call last):
  File "<pyshell#31>", line 1, in <module>
    a+b
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
  File "<pyshell#28>", line 3, in __add__
    return self + other
RuntimeError: maximum recursion depth exceeded
>>> class Try_int(int):
	def __add__(self, other):
		return int(self) + int(other)
	def __sub__(self, other):
		return int(self) - int(other)

	
>>> a = Try_int(3)
>>> b = Try_int(5)
>>> a+b
8
>>> a - b
-2
>>> class int(int):
	def __add__(self,other):
		return int.__sub__(self, other)

	
>>> a = int('5')
>>> a
5
>>> b = int(3)
>>> a + b
2
>>> 
=============================== RESTART: Shell ===============================
>>> class Nint(int):
	def __radd(self, other):
		return int.__sub__(self, other)

	
>>> a = Nint(5)
>>> b = Nint(3)
>>> a+ b
8
>>> 1 + b
4
>>> 1 + a
6
>>> a + 1
6
>>> b +1
4
>>> 
=============================== RESTART: Shell ===============================
>>> class Nint(int):
	def __radd__(self, other):
		return int.__sub__(self, other)

	
>>> a = Nint(5)
>>> b = Nint(3)
>>> a + b
8
>>> 1 + b
2
>>> 
=============================== RESTART: Shell ===============================
>>> class Nint(int):
	def __rsub__(self, other):
		return int.__sub__(self, other)

	
>>> a = Nint(5)
>>> 3 - a
2
>>> class A():
	def __str__(self):
		return '小甲鱼是帅哥！'

	
>>> a = A()
>>> print(a)
小甲鱼是帅哥！
>>> a
<__main__.A object at 0x02E2E710>
>>> class B():
	def __repr__(self):
		return '小甲鱼是帅哥！'

	
>>> b = B()
>>> b
小甲鱼是帅哥！
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
<__main__.MyTimer object at 0x02DEBE50>
>>> t1.start()
计时开始...
>>> t1.stop
<bound method MyTimer.stop of <__main__.MyTimer object at 0x02DEBE50>>
>>> t1.stop()
计时结束！
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
Traceback (most recent call last):
  File "<pyshell#91>", line 1, in <module>
    t1.stop()
  File "D:/python练习/MyTimer.py", line 12, in stop
    self._calc()
  File "D:/python练习/MyTimer.py", line 20, in _calc
    self.lasted.append(self.stop[intdex] - self.start[index])
NameError: name 'intdex' is not defined
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
总共运行了000004
计时结束！
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> t1
总共运行了000003
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
Traceback (most recent call last):
  File "<pyshell#107>", line 1, in <module>
    t1
  File "D:\Program Files (x86)\Python\lib\idlelib\rpc.py", line 611, in displayhook
    text = repr(value)
  File "D:/python练习/MyTimer.py", line 6, in __str__
    return self.prompt
AttributeError: 'MyTimer' object has no attribute 'prompt'
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
未开始计时！
>>> t1.start()
Traceback (most recent call last):
  File "<pyshell#110>", line 1, in <module>
    t1.start()
TypeError: 'int' object is not callable
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
未开始计时！
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> t1
总共运行了000003
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
Traceback (most recent call last):
  File "<pyshell#118>", line 1, in <module>
    t1.stop()
  File "D:/python练习/MyTimer.py", line 23, in stop
    self._calc()
  File "D:/python练习/MyTimer.py", line 32, in _calc
    if lasted[index]:
NameError: name 'lasted' is not defined
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> t1
总共运行了4秒
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
未开始计时！
>>> t1.stop()
提示：请先调用start()进行计时!
>>> t1.start()
计时开始...
>>> t1
提示：请先调用stop()停止计时！
>>> t1.stop()
计时结束！
>>> t1
总共运行了26秒
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1
未开始计时！
>>> t1.stop()
提示：请先调用start()进行计时!
>>> t1.start()
计时开始...
>>> t1
提示：请先调用stop()停止计时！
>>> t1.stop()
计时结束！
>>> t1
总共运行了3分钟-28秒
>>> t2 = MyTimer()
>>> t2.start()
计时开始...
>>> t2.stop()
计时结束！
>>> t2
总共运行了5秒
>>> t1 + t2
Traceback (most recent call last):
  File "<pyshell#141>", line 1, in <module>
    t1 + t2
  File "D:/python练习/MyTimer.py", line 22, in __add__
    promt += (str(result[index]) + self.unit[index])
UnboundLocalError: local variable 'promt' referenced before assignment
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> t1
总共运行了4秒
>>> t2 =MyTimer()
>>> t2.start()
计时开始...
>>> t2.stop()
计时结束！
>>> t2
总共运行了3秒
>>> t1 + t2
>>> 
====================== RESTART: D:/python练习/MyTimer.py ======================
>>> t1 = MyTimer()
>>> t1.start()
计时开始...
>>> t1.stop()
计时结束！
>>> t1
总共运行了3秒
>>> t2 = MyTimer()
>>> t2.start()
计时开始...
>>> t2.stop()
计时结束！
>>> t2
总共运行了3秒
>>> t1 + t2
'总共运行了6秒'
>>> class C:
	def __init__(self):
		self.x = 'X-man'

		
>>> c = C()
>>> c.x
'X-man'
>>> getattr(c, 'x', '木有这个属性')
'X-man'
>>> getattr(c, 'y', '木有这个属性')
'木有这个属性'
>>> 
=============================== RESTART: Shell ===============================
>>> class C:
	def __init__(self, size=10):
		self.size = size
	def getSize(self):
		return self.size
	def setSize(self, value):
		self.size = value
	def delSize(self):
		del self.size
	x = property(getSize, setSize, delSize)

	
>>> c = C()
>>> c.x = 1
>>> c.x
1
>>> c.size
1
>>> del c.x
>>> c.size
Traceback (most recent call last):
  File "<pyshell#184>", line 1, in <module>
    c.size
AttributeError: 'C' object has no attribute 'size'
>>> 
=============================== RESTART: Shell ===============================
>>> class C:
	def __getattribute__(self, name):
		print("getattribute")
		return super().__getattribute__(name)
	def __getattr__(self, name, value):
		print("getattr")
	def __setattr__(self, name, value):
		print("setattr")
		super().__setattr__(name,value)
	del __delattr__(self, name):
		
SyntaxError: invalid syntax
>>> class C:
	def __getattribute__(self, name):
		print("getattribute")
		return super().__getattribute__(name)
	def __getattr__(self, name, value):
		print("getattr")
	def __setattr__(self, name, value):
		print("setattr")
		super().__setattr__(name,value)
	del __delattr__(self, name):
		
SyntaxError: invalid syntax
>>> SyntaxError: invalid syntax
SyntaxError: invalid syntax
>>> class C:
	def __getattribute__(self, name):
		print("getattribute")
		return super().__getattribute__(name)
	def __getattr__(self, name, value):
		print("getattr")
	def __setattr__(self, name, value):
		print("setattr")
		super().__setattr__(name,value)
	del __delattr__(self, name):
		
SyntaxError: invalid syntax
>>> class C:
	def __getattribute__(self, name):
		print("getattribute")
		return super().__getattribute__(name)
	def __getattr__(self, name, value):
		print("getattr")
	def __setattr__(self, name, value):
		print("setattr")
		super().__setattr__(name,value)
	del __delattr__(self, name):
		
SyntaxError: invalid syntax
>>> class C:
	def __getattribute__(self, name):
		print("getattribute")
		return super().__getattribute__(name)
	def __getattr__(self, name):
		print("getattr")
	def __setattr__(self, name, value):
		print("setattr")
		super().__setattr__(name,value)
	def __delattr__(self, name):
		print("delattr")
		super().__delattr__(name)

		
>>> c = C()
>>> c.x
getattribute
getattr
>>> c.x = 1
setattr
>>> c.x
getattribute
1
>>> del c.x
delattr
>>> 
===================== RESTART: D:/python练习/rectangle.py =====================
>>> r1 = Rectangle(4,5)
Traceback (most recent call last):
  File "<pyshell#209>", line 1, in <module>
    r1 = Rectangle(4,5)
  File "D:/python练习/rectangle.py", line 3, in __init__
    self.width = width
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
  File "D:/python练习/rectangle.py", line 11, in __setattr__
    self.name = value
RuntimeError: maximum recursion depth exceeded while calling a Python object
>>> 
===================== RESTART: D:/python练习/rectangle.py =====================
>>> r1 = Rectangle(4, 5)
>>> r1.getArea()
20
>>> r1.square = 10
>>> r1.width
10
>>> r1.height
10
>>> r1.getArea()
100
>>> r1.__dict__
{'height': 10, 'width': 10}
>>> 
===================== RESTART: D:/python练习/rectangle.py =====================
>>> r1 =Rectangle(4,5)
>>> r1.getArea()
20
>>> r1.square = 10
>>> r1.getArea()
100
>>> 
===================== RESTART: D:/python练习/rectangle.py =====================
>>> r1 = Rectangle(4, 5)
>>> r1.getArea()
20
>>> r1.square = 10
>>> r1.getArea()
100
>>> 
