Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 19:28:18) [MSC v.1600 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> import random
>>> secret = random.randint(1, 10)
>>> secret
9
>>> import os
>>> os.getcwd()
'D:\\Program Files (x86)\\Python'
>>> os.chdir('E:\\')
>>> os.getcwd
<built-in function getcwd>
>>> os.getcwd()
'E:\\'
>>> os.listdir()
['$RECYCLE.BIN', '3-学生选课数据库的SQL脚本——创建视图、函数、过程、触发器.sql', '360Downloads', 'AllinRepeater', 'asp.net从入门到精通', 'BaiduYunDownload', 'C#入门经典（第五版）中英文高清及源码.rar', 'C／C__程序员面试宝典.pdf', 'Gridview', 'initrd.lz', 'KuGou', 'KuGouCache', 'OnLineExam', 'QQMusicCache', 'repeater实例（未调试通过）.RAR', 'System Volume Information', 'vmlinuz.efi', 'workspace', '在线考试系统', '垃圾收集器.c', '安卓开发', '手机淘宝项目和文档.rar', '排序.cpp', '程序员面试宝典（第三版）.pdf', '编程文档', '角色管理与授权机制']
>>> os.chdir('D:\\Program Files (x86)\\Python')
>>> os.listdir
<built-in function listdir>
>>> os.listdir()
['DLLs', 'Doc', 'include', 'Lib', 'libs', 'LICENSE.txt', 'NEWS.txt', 'python.exe', 'pythonw.exe', 'README.txt', 'Scripts', 'tcl', 'Tools']
>>> os.getcwd()
'D:\\Program Files (x86)\\Python'
>>> os.mkdir('D:\\Program Files (x86)\\Python\\A')
>>> os.listdir()
['A', 'DLLs', 'Doc', 'include', 'Lib', 'libs', 'LICENSE.txt', 'NEWS.txt', 'python.exe', 'pythonw.exe', 'README.txt', 'Scripts', 'tcl', 'Tools']
>>> os.removedir
Traceback (most recent call last):
  File "<pyshell#15>", line 1, in <module>
    os.removedir
AttributeError: 'module' object has no attribute 'removedir'
>>> os.removedir('D:\\Program Files (x86)\\Python\\A')
Traceback (most recent call last):
  File "<pyshell#16>", line 1, in <module>
    os.removedir('D:\\Program Files (x86)\\Python\\A')
AttributeError: 'module' object has no attribute 'removedir'
>>> os.removedirs('D:\\Program Files (x86)\\Python\\A')
>>> os.listdir
<built-in function listdir>
>>> os.listdir()
['DLLs', 'Doc', 'include', 'Lib', 'libs', 'LICENSE.txt', 'NEWS.txt', 'python.exe', 'pythonw.exe', 'README.txt', 'Scripts', 'tcl', 'Tools']
>>> os.system('cmd')
-1073741510
>>> os.system('calc')
-1073741510
>>> os.curdir
'.'
>>> os.listdir(os.curdir)
['DLLs', 'Doc', 'include', 'Lib', 'libs', 'LICENSE.txt', 'NEWS.txt', 'python.exe', 'pythonw.exe', 'README.txt', 'Scripts', 'tcl', 'Tools']
>>> os.path.basename(''D:\\Program Files (x86)\\Python'')
SyntaxError: invalid syntax
>>> os.path.basename(''D:\\Program Files (x86)'')
SyntaxError: invalid syntax
>>> os.path.basename('D:\\Program Files (x86)\\Python')
'Python'
>>> os.path.dirname('D:\\Program Files (x86)\\Python')
'D:\\Program Files (x86)'
>>> os.path.join('A','B','C')
'A\\B\\C'
>>> os.path.join('C:\\','A','B')
'C:\\A\\B'
>>> os.path.getatime('D:\\Program Files (x86)\\Python\\NEWS.txt')
1457255667.2902923
>>> import time
>>> time.gmtime(os.path.getatime('D:\\Program Files (x86)\\Python\\NEWS.txt'))
time.struct_time(tm_year=2016, tm_mon=3, tm_mday=6, tm_hour=9, tm_min=14, tm_sec=27, tm_wday=6, tm_yday=66, tm_isdst=0)
>>> time.localtime(os.path.getatime('D:\\Program Files (x86)\\Python\\NEWS.txt'))
time.struct_time(tm_year=2016, tm_mon=3, tm_mday=6, tm_hour=17, tm_min=14, tm_sec=27, tm_wday=6, tm_yday=66, tm_isdst=0)
>>> os.path.ismount()
Traceback (most recent call last):
  File "<pyshell#34>", line 1, in <module>
    os.path.ismount()
TypeError: ismount() missing 1 required positional argument: 'path'
>>> os.path.ismount("E:\\")
True
>>> os.path.ismount("E:\\A")
False
>>> import pickle
>>> my_list = [123, 3.14, '小甲鱼', ['another list']]
>>> pickle_file = open('my_list.pkl','wb')
>>> pickle.dump(my_list, pickle_file)
>>> pickle_file.close()
>>> pickle_file('my_list.pkl','rb')
Traceback (most recent call last):
  File "<pyshell#42>", line 1, in <module>
    pickle_file('my_list.pkl','rb')
TypeError: '_io.BufferedWriter' object is not callable
>>> pickle_file=open('my_list.pkl','rb')
>>> my_list2=pickle.load(pickle_file)
>>> pirnt(my_list2)
Traceback (most recent call last):
  File "<pyshell#45>", line 1, in <module>
    pirnt(my_list2)
NameError: name 'pirnt' is not defined
>>> print(my_list2)
[123, 3.14, '小甲鱼', ['another list']]
>>> 
======================= RESTART: D:/python练习/test3.py =======================
请输入需要打开的文件名：record
Traceback (most recent call last):
  File "D:/python练习/test3.py", line 2, in <module>
    f = open(file_name)
FileNotFoundError: [Errno 2] No such file or directory: 'record'
>>> record.txt
Traceback (most recent call last):
  File "<pyshell#47>", line 1, in <module>
    record.txt
NameError: name 'record' is not defined
>>> record.txt
Traceback (most recent call last):
  File "<pyshell#48>", line 1, in <module>
    record.txt
NameError: name 'record' is not defined
>>> 
======================= RESTART: D:/python练习/test3.py =======================
请输入需要打开的文件名：record.txt
文件的内容是：
小客服:小甲鱼，今天有客户问你有没有女朋友？

小甲鱼:咦？？

小客服:我跟她说你有女朋友了！

小甲鱼:。。。。。。

小客服:她让你分手后考虑下她！然后我说“您要买个优盘，我及帮你留一下~”

小甲鱼:然后呢？

小客服:她买了两个，说发一个货就好~

小甲鱼:呃。。。。。。你真牛！

小客服:那是，谁让我是鱼C最可爱小客服嘛~

小甲鱼:下次有人想调戏你我不阻止~

小客服:滚！！！

========================================================================================

小客服:小甲鱼，有个好评很好笑哈。

小甲鱼:哦？

小客服:"有了小甲鱼，以后妈妈再也不用担心我的学习了~"

小甲鱼:哈哈哈，我看到丫，我还发微博了呢~

小客服:嗯嗯，我看了你发的微博丫~

小甲鱼:呦西~

小客服:那个有条回复"左手拿着小甲鱼，右手拿着打火机，哪里不会点哪里，so easy ^_^"

小甲鱼:T_T

========================================================================================

小客服:小甲鱼，今天一个会员想找你

小甲鱼:哦？什么事？

小客服:他说你一个学生月薪已经超过12k了！！

小甲鱼:哪里的？

小客服:上海的

小甲鱼:那正常，哪家公司？

小客服:他没说呀。

小甲鱼:哦

小客服:老大，为什么我工资那么低啊？？是时候涨涨工资了！！

小甲鱼:啊，你说什么？我在外边呢，这里好吵吖。。。。。。

小客服:滚！！！
>>> my_list = ['小甲鱼是帅哥']
>>> assert len(my_list) > 0
>>> my_list.pop()
'小甲鱼是帅哥'
>>> assert len(my_list) > 0
Traceback (most recent call last):
  File "<pyshell#52>", line 1, in <module>
    assert len(my_list) > 0
AssertionError
>>> my_list.fishc
Traceback (most recent call last):
  File "<pyshell#53>", line 1, in <module>
    my_list.fishc
AttributeError: 'list' object has no attribute 'fishc'
>>> my_list = [1, 2, 3]
>>> my_list[3]
Traceback (most recent call last):
  File "<pyshell#55>", line 1, in <module>
    my_list[3]
IndexError: list index out of range
>>> my_list[2]
3
>>> my_dict = {'one':1, 'two':2, 'three':3}
>>> my_dict['one']
1
>>> my_dict['four']
Traceback (most recent call last):
  File "<pyshell#59>", line 1, in <module>
    my_dict['four']
KeyError: 'four'
>>> my_dict.get('four')
>>> print 'I love fishC.com'
SyntaxError: Missing parentheses in call to 'print'
>>> print('I love fishC.com')
I love fishC.com
>>> 1 + '1'
Traceback (most recent call last):
  File "<pyshell#63>", line 1, in <module>
    1 + '1'
TypeError: unsupported operand type(s) for +: 'int' and 'str'
>>> 5 / 0
Traceback (most recent call last):
  File "<pyshell#64>", line 1, in <module>
    5 / 0
ZeroDivisionError: division by zero
>>> 
======================= RESTART: D:/python练习/test4.py =======================
Traceback (most recent call last):
  File "D:/python练习/test4.py", line 1, in <module>
    f = open('我为什么是一个文件.txt')
FileNotFoundError: [Errno 2] No such file or directory: '我为什么是一个文件.txt'
>>> 
======================= RESTART: D:/python练习/test4.py =======================
文件出错了！
>>> 
======================= RESTART: D:/python练习/test4.py =======================
文件出错了！
错误的原因是：[Errno 2] No such file or directory: '我为什么是一个文件.txt'
>>> 
======================= RESTART: D:/python练习/test4.py =======================
类型出错了！
错误的原因是：unsupported operand type(s) for +: 'int' and 'str'
>>> 
======================= RESTART: D:/python练习/test4.py =======================
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
5
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
5
出错了
>>> 
======================= RESTART: D:/python练习/test4.py =======================
5
出错了
>>> raise
Traceback (most recent call last):
  File "<pyshell#65>", line 1, in <module>
    raise
RuntimeError: No active exception to reraise
>>> raise ZeroDivisionError
Traceback (most recent call last):
  File "<pyshell#66>", line 1, in <module>
    raise ZeroDivisionError
ZeroDivisionError
>>> raise ZeroDivisionError('除数为零的异常')
Traceback (most recent call last):
  File "<pyshell#67>", line 1, in <module>
    raise ZeroDivisionError('除数为零的异常')
ZeroDivisionError: 除数为零的异常
>>> 
======================= RESTART: D:/python练习/test5.py =======================
请输入一个数：2
2是素数！
>>> 
======================= RESTART: D:/python练习/test5.py =======================
请输入一个数：3
3是素数！
>>> 
======================= RESTART: D:/python练习/test5.py =======================
请输入一个数：7
7是素数！
>>> 
======================= RESTART: D:/python练习/test5.py =======================
请输入一个数：8
8最大的约数是4
>>> 
======================= RESTART: D:/python练习/test5.py =======================
请输入一个数：9
9最大的约数是3
>>> 
======================= RESTART: D:/python练习/test6.py =======================
出错啦：invalid literal for int() with base 10: 'abc'
>>> 
======================= RESTART: D:/python练习/test6.py =======================
123
没有任何异常！
>>> 
======================= RESTART: D:/python练习/test7.py =======================
出错啦：not readable
>>> 
======================= RESTART: D:/python练习/test7.py =======================
出错啦：not readable
>>> 
======================= RESTART: D:/python练习/test7.py =======================
出错啦：not readable
>>> 
======================= RESTART: D:/python练习/test8.py =======================
>>> tt = Turtle()
>>> tt.climb()
我正在很努力的向前爬……
>>> tt.bite()
咬死你咬死你！！
>>> tt.sleep()
困了，睡了，晚安，Zzzz
>>> list1 = [2,1 ,7, 5,3]
>>> list.sort()
Traceback (most recent call last):
  File "<pyshell#73>", line 1, in <module>
    list.sort()
TypeError: descriptor 'sort' of 'list' object needs an argument
>>> list1.sort()
>>> list1
[1, 2, 3, 5, 7]
>>> list1.append(9)
>>> list1
[1, 2, 3, 5, 7, 9]
>>> class MyList(list):
	pass

>>> list2 = MyList()
>>> list2.append(5)
>>> list2.append(3)
>>> list2.append(7)
>>> list2
[5, 3, 7]
>>> list2.sort()
>>> list2
[3, 5, 7]
>>> class A:
	def fun(self):
		print("我是小A...")

		
>>> class B:
	def fun(self):
		print("我是小B...")

		
>>> a = A()
>>> b = B()
>>> a.fun()
我是小A...
>>> b.fun()
我是小B...
>>> class Ball:
	def setName(self, name):
		self.name = name

		
>>> class Ball:
	def setName(self, name):
		self.name = name
	def kick(self):
		print("我叫%s，该死的，谁踢我..." % self.name)

		
>>> a = Ball()
>>> a.setName('求A')
>>> b = Ball()
>>> b.setName('球B')
>>> c = Ball()
>>> c.setName('土豆')
>>> a.kick()
我叫求A，该死的，谁踢我...
>>> c.kick()
我叫土豆，该死的，谁踢我...
>>> b.kick()
我叫球B，该死的，谁踢我...
>>> class Ball:
	def __init__(self, name):
		self.name = name
	def kick(self)
	
SyntaxError: invalid syntax
>>> class Ball:
	def __init__(self, name):
		self.name = name
	def kick(self):
		print('我叫%s,该死的，谁踢我...' % self.name)

		
>>> b = Ball('土豆')
>>> b.kick()
我叫土豆,该死的，谁踢我...
>>> class Person:
	name = '小甲鱼'

	
>>> p = Person()
>>> p.name
'小甲鱼'
>>> class Person:
	__name = '小甲鱼'
	p.name

	
>>> p.name
'小甲鱼'
>>> class Person:
	__name = '小甲鱼'
	def getName(self):
		return self.__name

	
>>> p = Person()
>>> p.__name
Traceback (most recent call last):
  File "<pyshell#144>", line 1, in <module>
    p.__name
AttributeError: 'Person' object has no attribute '__name'
>>> p.getName()
'小甲鱼'
>>> p._Person__name
'小甲鱼'
>>> class Parent:
	def hello(self):
		print("正在调用父类的方法...")

		
>>> class Child(Parent):
	pass

>>> p = Parent()
>>> p.hello()
正在调用父类的方法...
>>> c = Child()
>>> c.hello()
正在调用父类的方法...
>>> class Child(Parent):
	def hello(self):
		print("正在调用子类的方法...")

		
>>> c = Child()
>>> c.hello()
正在调用子类的方法...
>>> p.hello()
正在调用父类的方法...
>>> 
======================== RESTART: D:/python练习/fish.py ========================
>>> fish = Fish()
>>> fish.move()
我的位置是：%d,%d (9, 10)
>>> 
======================== RESTART: D:/python练习/fish.py ========================
>>> fish = Fish()
>>> fish.move()
我的位置是： 9 4
>>> fish.move()
我的位置是： 8 4
>>> goldfish = Goldfish()
>>> goldfish.move()
我的位置是： 6 10
>>> goldfish.move()
我的位置是： 5 10
>>> shark = Shark()
>>> shark.eat()
吃货的梦想就是天天有的吃^_^
>>> shark.eat()
太撑了，吃不下了！
>>> shark.move()
Traceback (most recent call last):
  File "<pyshell#176>", line 1, in <module>
    shark.move()
  File "D:/python练习/fish.py", line 9, in move
    self.x -= 1
AttributeError: 'Shark' object has no attribute 'x'
>>> 
======================== RESTART: D:/python练习/fish.py ========================
>>> shark = Shark()
>>> shark.move()
我的位置是： -1 8
>>> shark.move()
我的位置是： -2 8
>>> 
======================== RESTART: D:/python练习/fish.py ========================
>>> shark = Shark()
>>> shark.move()
我的位置是： 8 10
>>> class Base1:
	def foo1(self):
		print("我是foo1，我为Base1代言...")

		
>>> class Base2:
	def foo2(self):
		print("我是foo2，我为Base2代言...")

		
>>> class C(Base1,Base2):
	pass

>>> c = C()
>>> c.foo1()
我是foo1，我为Base1代言...
>>> c.foo2()
我是foo2，我为Base2代言...
>>> print('%d,%s' % (12, '哈哈'))
12,哈哈
>>> print('%d' % 12)
12
>>> print(12)
12
>>> 
======================== RESTART: D:/python练习/pool.py ========================
>>> pool = Pool(1, 10)
>>> pool.print_num()
Traceback (most recent call last):
  File "<pyshell#200>", line 1, in <module>
    pool.print_num()
  File "D:/python练习/pool.py", line 15, in print_num
    print("水池里总共有乌龟 % 只，小鱼 %d 条!" % (self.turtle.num, self.fish.num))
ValueError: unsupported format character '?' (0x53ea) at index 11
>>> 
======================== RESTART: D:/python练习/pool.py ========================
>>> pool = Pool(1, 10)
>>> pool.print_num()
水池里总共有乌龟 1 只，小鱼 10 条!
>>> class C:
	count = 0

	
>>> a = C()
>>> b = C()
>>> c = C()
>>> a.count
0
>>> b.count
0
>>> c.count
0
>>> c.count += 10
>>> c.count
10
>>> a.count
0
>>> b.count
0
>>> C.count
0
>>> C.count+=100
>>> a.count
100
>>> b.count
100
>>> c.count
10
>>> class C:
	def x(self):
		print("X-man!")

		
>>> c = C()
>>> c.x()
X-man!
>>> c.x =1
>>> c.x
1
>>> c.x()
Traceback (most recent call last):
  File "<pyshell#229>", line 1, in <module>
    c.x()
TypeError: 'int' object is not callable
>>>  class CC:
	 
SyntaxError: unexpected indent
>>> class CC:
	def setXY(self, x, y):
		self.x = x
		self.y = y
	def printXY(self):
		print(self.x, self.y)

		
>>> dd = CC()
>>> dd.__dict__
{}
>>> CC.__dict__
mappingproxy({'setXY': <function CC.setXY at 0x02E4DED0>, '__weakref__': <attribute '__weakref__' of 'CC' objects>, '__dict__': <attribute '__dict__' of 'CC' objects>, 'printXY': <function CC.printXY at 0x02E4DF18>, '__module__': '__main__', '__doc__': None})
>>> dd.setXY(4, 5)
>>> dd.__dict__
{'x': 4, 'y': 5}
>>> CC.__dict__
mappingproxy({'setXY': <function CC.setXY at 0x02E4DED0>, '__weakref__': <attribute '__weakref__' of 'CC' objects>, '__dict__': <attribute '__dict__' of 'CC' objects>, 'printXY': <function CC.printXY at 0x02E4DF18>, '__module__': '__main__', '__doc__': None})
>>> del CC
>>> ee = CC()
Traceback (most recent call last):
  File "<pyshell#245>", line 1, in <module>
    ee = CC()
NameError: name 'CC' is not defined
>>> dd.printXY()
4 5
>>> class A:
	pass

>>> class B(A):
	pass

>>> issubclass(B, A)
True
>>> issubclass(A, A)
True
>>> issubclass(B, object)
True
>>> class C:
	pass

>>> issubclass(B, C)
False
>>> b1 = B()
>>> isinstancee(b1, B)
Traceback (most recent call last):
  File "<pyshell#261>", line 1, in <module>
    isinstancee(b1, B)
NameError: name 'isinstancee' is not defined
>>> isinstance(b1, B)
True
>>> isinstance(b1, A)
True
>>> isinstance(b1, C)
False
>>> isinstance(b1, (A, C))
True
>>> isinstance(b1, (A, B, C))
True
>>> class C:
	def __init__(self, x = 0):
		self.x = x

		
>>> c1 = C()
>>> hasattr(c1, 'x')
True
>>> hasattr(c1, x)
Traceback (most recent call last):
  File "<pyshell#273>", line 1, in <module>
    hasattr(c1, x)
NameError: name 'x' is not defined
>>> getattr(c1, 'x')
0
>>> getattr(c1, 'y', '您所访问的属性不存在……')
'您所访问的属性不存在……'
>>> setattr(c1, 'y', 'FishC')
>>> getattr(c1, 'y', '您所访问的属性不存在……')
'FishC'
>>> delattr(c1, 'y')
>>> delattr(c1, 'y')
Traceback (most recent call last):
  File "<pyshell#279>", line 1, in <module>
    delattr(c1, 'y')
AttributeError: y
>>> class C:
	def __init__(self, size = 10):
		self.size = size

		
>>> class C:
	def __init__(self, size = 10):
		self.size = size
	def getSize(self):
		return self.size
	def setSize(self, value):
		self.size = value
	def delSize(self):
		del self.size
	x = property(getSize, setSize, delSize)

	
>>> c1 = C()
>>> c1.getSize()
10
>>> c1.x
10
>>> c1.x = 18
>>> c1.x
18
>>> c1.size
18
>>> c1.getSize()
18
>>> del c1.x
>>> c1.size
Traceback (most recent call last):
  File "<pyshell#301>", line 1, in <module>
    c1.size
AttributeError: 'C' object has no attribute 'size'
>>> class Rectangle:
	def __init__(self, x, y):
		self.x = x
		self.y = y
	def getPeri(self):
		return (self.x + self.y) * 2
	def getArea(self):
		return self.x * self.y

	
>>> rect = Rectangle(3, 4)
>>> rect.getPeri()
14
>>> rect.getArea()
12
>>> class CapStr(str):
	def __new__(cls, string):
		string = string.upper()
		return str.__new__(cls, string)

	
>>> a = CapStr("I love FishC.com")
>>> a
'I LOVE FISHC.COM'
>>> class C:
	def __init__(self):
		print("我是__init__方法，我被调用了……")
	def __del__(self):
		print("我是__del__方法，我被调用了……")

		
>>> c1 = C()
我是__init__方法，我被调用了……
>>> c2 = c1
>>> c3 =c2
>>> del c3
>>> del c2
>>> del c1
我是__del__方法，我被调用了……
>>> 
