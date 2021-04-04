Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 19:28:18) [MSC v.1600 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> 
===================== RESTART: D:\python练习\wordgame_1.py =====================
---------我是小甲鱼工作室-----------
不妨猜一下小甲鱼现在现在心里想的是哪个数字：1
哎呀，猜错了，请重新输入吧：1
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：1
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：1
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：1
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：18
哥，大了大了~~
哎呀，猜错了，请重新输入吧：8
我草，你是小甲鱼心里的蛔虫吗？
哼，猜中了也没有奖励
哎呀，猜错了，请重新输入吧：8
我草，你是小甲鱼心里的蛔虫吗？
哼，猜中了也没有奖励
哎呀，猜错了，请重新输入吧：9
哥，大了大了~~
哎呀，猜错了，请重新输入吧：3
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：3
嘿，小了，小了！！
哎呀，猜错了，请重新输入吧：8
我草，你是小甲鱼心里的蛔虫吗？
哼，猜中了也没有奖励

Traceback (most recent call last):
  File "D:\python练习\wordgame_1.py", line 34, in <module>
    guess=int(temp)
ValueError: invalid literal for int() with base 10: ''
>>> a=0.000000000000000000000025
>>> a
2.5e-23
>>> 150000000000000000000000000000000
150000000000000000000000000000000
>>> 150000000000
150000000000
>>> 1.5e11
150000000000.0
>>> 15e10
150000000000.0
>>> 1.5e4
15000.0
>>> True+True
2
>>> True+False
1
>>> True*False
0
>>> True/False
Traceback (most recent call last):
  File "<pyshell#10>", line 1, in <module>
    True/False
ZeroDivisionError: division by zero
>>> a='520'
>>> b=int(520)
>>> b
520
>>> b=int('胸啊驾驭')
Traceback (most recent call last):
  File "<pyshell#14>", line 1, in <module>
    b=int('胸啊驾驭')
ValueError: invalid literal for int() with base 10: '胸啊驾驭'
>>> b=int(a)
>>> b
520
>>> b=int(A)
Traceback (most recent call last):
  File "<pyshell#17>", line 1, in <module>
    b=int(A)
NameError: name 'A' is not defined
>>> a=5.99
>>> c=int(a)
>>> c
5
>>> a='520'
>>> b=float(a)
>>> b
520.0
>>> a=520
>>> b=float(a)
>>> b
520.0
>>> a=5.99
>>> b=str(a)
>>> b
'5.99'
>>> c=str(5e19)
>>> c
'5e+19'
>>> str='I love fishc.com'
>>> str
'I love fishc.com'
>>> c=str(5e19)
Traceback (most recent call last):
  File "<pyshell#34>", line 1, in <module>
    c=str(5e19)
TypeError: 'str' object is not callable
>>> 
===================== RESTART: D:\python练习\wordgame_1.py =====================
---------我是小甲鱼工作室-----------
不妨猜一下小甲鱼现在现在心里想的是哪个数字：nineo
Traceback (most recent call last):
  File "D:\python练习\wordgame_1.py", line 30, in <module>
    guess=int(temp)
ValueError: invalid literal for int() with base 10: 'nineo'
>>> a='520'
>>> type(a)
<class 'str'>
>>> type(5.2)
<class 'float'>
>>> type(true)
Traceback (most recent call last):
  File "<pyshell#38>", line 1, in <module>
    type(true)
NameError: name 'true' is not defined
>>> type(True)
<class 'bool'>
>>> type(5e15)
<class 'float'>
>>> a='小甲鱼'
>>> isinstance(a,str)
True
>>> isinstance(a,int)
False
>>> isinstance(320,int)
True
>>> isinstance(320.25,float)
True
>>> isinstance(320.25,bool)
False
>>> a=5
>>> a+=3
>>> a
8
>>> b-=1
Traceback (most recent call last):
  File "<pyshell#50>", line 1, in <module>
    b-=1
NameError: name 'b' is not defined
>>> b=3
>>> b-=3
>>> a
8
>>> b
0
>>> a
8
>>> a=b=c=d=10
>>> a+=1
>>> b-=3
>>> c*=10
>>> d/=8
>>> a
11
>>> b
7
>>> c
100
>>> d
1.25
>>> d=10
>>> d//=8
>>> d
1
>>> 3.0//2
1.0
>>> 5/2
2.5
>>> 5@3
SyntaxError: invalid syntax
>>> 5 % 2
1
>>> 3 ** 2
9
>>> 3 ** 5
243
>>> -3*2+5/-2-4
-12.5
>>> -3 ** 2
-9
>>> 2** -2
0.25
>>> not True
False
>>> not 0
True
>>> not False
True
>>> not 4
False
>>> 3<4<5
True
>>> assert 3 > 4
Traceback (most recent call last):
  File "<pyshell#82>", line 1, in <module>
    assert 3 > 4
AssertionError
>>> assert 4 > 3
>>> favourite='FishC'
>>> for i in favourite:
	print(i,end=' ')

	
F i s h C 
>>> member = ['小甲鱼', '小布丁' , '黑夜', '迷途'， '怡静’]
	  
SyntaxError: invalid character in identifier
>>> member = ['小甲鱼', '小布丁' , '黑夜', '迷途', '怡静’]
	  
SyntaxError: EOL while scanning string literal
>>> member = ['小甲鱼', '小布丁' , '黑夜', '迷途', '怡静']
>>> for each in member:
	print(each,len(member))

	
小甲鱼 5
小布丁 5
黑夜 5
迷途 5
怡静 5
>>> for each in member:
	print(each,len(each))

	
小甲鱼 3
小布丁 3
黑夜 2
迷途 2
怡静 2
>>> range(5)
range(0, 5)
>>> list(range(5))
[0, 1, 2, 3, 4]
>>> for i in range(5):
	print(i)

	
0
1
2
3
4
>>> for i in range(2,9):
	print(i)

	
2
3
4
5
6
7
8
>>> for i in range(1,10,2):
	print(i)

	
1
3
5
7
9
>>> 
====================== RESTART: D:/python练习/example1.py ======================
情输入小甲鱼最想听的一句话：艾哈
抱歉，错了，请重新输入（答案正确才能退出游戏）：小甲鱼是帅哥
哎呦，帅哦~
您真是小甲鱼肚子里的蛔虫啊^_^
>>> 
====================== RESTART: D:/python练习/example2.py ======================
2
1
4
3
6
5
8
7
10
9
>>> 
====================== RESTART: D:/python练习/example2.py ======================
0
2
1
1
2
4
3
3
4
6
5
5
6
8
7
7
8
10
9
9
>>> 
====================== RESTART: D:/python练习/example2.py ======================
0
100
1
1
2
102
3
3
4
104
5
5
6
106
7
7
8
108
9
9
>>> 
====================== RESTART: D:/python练习/example2.py ======================
100
1
102
3
104
5
106
7
108
9
>>> member = ['小甲鱼', '小布丁', '黑夜', '迷途', '怡静']
>>> member
['小甲鱼', '小布丁', '黑夜', '迷途', '怡静']
>>> number = [1,2,3,4,5]
>>> numnber
Traceback (most recent call last):
  File "<pyshell#110>", line 1, in <module>
    numnber
NameError: name 'numnber' is not defined
>>> number
[1, 2, 3, 4, 5]
>>> mix = [1, '小甲鱼', 3.14, [1, 2, 3]]
>>> mix
[1, '小甲鱼', 3.14, [1, 2, 3]]
>>> empty = []
>>> empty
[]
>>> member
['小甲鱼', '小布丁', '黑夜', '迷途', '怡静']
>>> member.append("福禄娃娃")
>>> member
['小甲鱼', '小布丁', '黑夜', '迷途', '怡静', '福禄娃娃']
>>> len(member)
6
>>> member.append("竹林小溪","Crazy迷恋")
Traceback (most recent call last):
  File "<pyshell#120>", line 1, in <module>
    member.append("竹林小溪","Crazy迷恋")
TypeError: append() takes exactly one argument (2 given)
>>> member.extend("竹林小溪","Crazy迷恋")
Traceback (most recent call last):
  File "<pyshell#121>", line 1, in <module>
    member.extend("竹林小溪","Crazy迷恋")
TypeError: extend() takes exactly one argument (2 given)
>>> member.extend(["竹林小溪","Crazy迷恋"])
>>> member
['小甲鱼', '小布丁', '黑夜', '迷途', '怡静', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> len(member)
8
>>> member.insert(1,'牡丹')
>>> member
['小甲鱼', '牡丹', '小布丁', '黑夜', '迷途', '怡静', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> member[0]
'小甲鱼'
>>> member[1]
'牡丹'
>>> temp=member[0]
>>> member[0]=member[1]
>>> member[1]=temp
>>> member
['牡丹', '小甲鱼', '小布丁', '黑夜', '迷途', '怡静', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> member.remove('怡静')
>>> member
['牡丹', '小甲鱼', '小布丁', '黑夜', '迷途', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> len(member)
8
>>> member.remove('小鱼儿')
Traceback (most recent call last):
  File "<pyshell#136>", line 1, in <module>
    member.remove('小鱼儿')
ValueError: list.remove(x): x not in list
>>> del member[1]
>>> member
['牡丹', '小布丁', '黑夜', '迷途', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> del member
>>> len(member)
Traceback (most recent call last):
  File "<pyshell#140>", line 1, in <module>
    len(member)
NameError: name 'member' is not defined
>>> member=['牡丹', '小布丁', '黑夜', '迷途', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> member
['牡丹', '小布丁', '黑夜', '迷途', '福禄娃娃', '竹林小溪', 'Crazy迷恋']
>>> member.pop（）
SyntaxError: invalid character in identifier
>>> member.pop()
'Crazy迷恋'
>>> name=member.pop()
>>> name
'竹林小溪'
>>> member
['牡丹', '小布丁', '黑夜', '迷途', '福禄娃娃']
>>> member.pop(1)
'小布丁'
>>> member[1:3]
['黑夜', '迷途']
>>> member
['牡丹', '黑夜', '迷途', '福禄娃娃']
>>> memer[:3]
Traceback (most recent call last):
  File "<pyshell#151>", line 1, in <module>
    memer[:3]
NameError: name 'memer' is not defined
>>> member[:3]
['牡丹', '黑夜', '迷途']
>>> member[1:]
['黑夜', '迷途', '福禄娃娃']
>>> member[:]
['牡丹', '黑夜', '迷途', '福禄娃娃']
>>> member2=member[:]
>>> member2
['牡丹', '黑夜', '迷途', '福禄娃娃']
>>> list1 = [123]
>>> list2 = [234]
>>> list1 > list2
False
>>> list1 = [123, 456]
>>> list2 = [234, 123]
>>> list1 > list2
False
>>> list3 = [123, 456]
>>> (list1 < list2) and (list1 == list3)
True
>>> list4 = list1 + list2
>>> list4
[123, 456, 234, 123]
>>> list1 + '小甲鱼'
Traceback (most recent call last):
  File "<pyshell#167>", line 1, in <module>
    list1 + '小甲鱼'
TypeError: can only concatenate list (not "str") to list
>>> list.append('小甲鱼')
Traceback (most recent call last):
  File "<pyshell#168>", line 1, in <module>
    list.append('小甲鱼')
TypeError: descriptor 'append' requires a 'list' object but received a 'str'
>>> list1.append('小甲鱼')
>>> lsit1
Traceback (most recent call last):
  File "<pyshell#170>", line 1, in <module>
    lsit1
NameError: name 'lsit1' is not defined
>>> list1
[123, 456, '小甲鱼']
>>> list3
[123, 456]
>>> list3 * 3
[123, 456, 123, 456, 123, 456]
>>> list3 *= 5
>>> list3
[123, 456, 123, 456, 123, 456, 123, 456, 123, 456]
>>> 123 in list3
True
>>> '小甲鱼' not in list3
True
>>> 123 not in list3
False
>>> list5 = [123, ['小甲鱼', '牡丹'], 456]
>>> '小甲鱼' in list5
False
>>> '小甲鱼' in list5[1]
True
>>> list5[1][1]
'牡丹'
>>> dir(list)
['__add__', '__class__', '__contains__', '__delattr__', '__delitem__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__gt__', '__hash__', '__iadd__', '__imul__', '__init__', '__iter__', '__le__', '__len__', '__lt__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__reversed__', '__rmul__', '__setattr__', '__setitem__', '__sizeof__', '__str__', '__subclasshook__', 'append', 'clear', 'copy', 'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort']
>>> list3.coun
Traceback (most recent call last):
  File "<pyshell#184>", line 1, in <module>
    list3.coun
AttributeError: 'list' object has no attribute 'coun'
>>> list3.count(123)
5
>>> list3.index(123)
0
>>> list3.index(123,3,7)
4
>>> list3.reverse()
>>> list3
[456, 123, 456, 123, 456, 123, 456, 123, 456, 123]
>>> list6 = [4, 2, 5, 1 9 ,23, 32 ,0]
SyntaxError: invalid syntax
>>> list6.sort()
Traceback (most recent call last):
  File "<pyshell#191>", line 1, in <module>
    list6.sort()
NameError: name 'list6' is not defined
>>> list6 = [4, 2, 5, 1, 9 ,23, 32 ,0]
>>> list6.sort()
>>> list6
[0, 1, 2, 4, 5, 9, 23, 32]
>>> list6.sort(reverse=True)
>>> list6
[32, 23, 9, 5, 4, 2, 1, 0]
>>> list7 = list6[:]
>>> list7
[32, 23, 9, 5, 4, 2, 1, 0]
>>> list8 = list6
>>> list8
[32, 23, 9, 5, 4, 2, 1, 0]
>>> list6.sort()
>>> list6
[0, 1, 2, 4, 5, 9, 23, 32]
>>> list7
[32, 23, 9, 5, 4, 2, 1, 0]
>>> list8
[0, 1, 2, 4, 5, 9, 23, 32]
>>> tuple1 = (1,2,3,4,5,6,7,8)
>>> tuple1
(1, 2, 3, 4, 5, 6, 7, 8)
>>> tuple1[1]
2
>>> tuple1[5:]
(6, 7, 8)
>>> tuple1[:5]
(1, 2, 3, 4, 5)
>>> tuple2 = tuple1[:]
>>> tuple2
(1, 2, 3, 4, 5, 6, 7, 8)
>>> tuple1[1] = 3
Traceback (most recent call last):
  File "<pyshell#212>", line 1, in <module>
    tuple1[1] = 3
TypeError: 'tuple' object does not support item assignment
>>> temp = (1)
>>> temp
1
>>> type(temp)
<class 'int'>
>>> type(tuple1)
<class 'tuple'>
>>> temp2 = 2,3,4
>>> type(temp2)
<class 'tuple'>
>>> temp=[]
>>> type(temp)
<class 'list'>
>>> temp=()
>>> type(temp)
<class 'tuple'>
>>> temp = (1,)
>>> type(tuple)
<class 'type'>
>>> type(tep)
Traceback (most recent call last):
  File "<pyshell#225>", line 1, in <module>
    type(tep)
NameError: name 'tep' is not defined
>>> type(temp)
<class 'tuple'>
>>> tep=1,
>>> type(tep)
<class 'tuple'>
>>>  8 * (8)
 
SyntaxError: unexpected indent
>>> 8 * (8,)
(8, 8, 8, 8, 8, 8, 8, 8)
>>> 8 * (8)
64
>>> temp = ('小甲鱼', '黑夜', '迷途', '小布丁')
>>> temp = temp[:2]+('怡静',)+temp[2:]
>>> temp
('小甲鱼', '黑夜', '怡静', '迷途', '小布丁')
>>> del temp
>>> temp
Traceback (most recent call last):
  File "<pyshell#236>", line 1, in <module>
    temp
NameError: name 'temp' is not defined
>>> str1 = 'I love fishc.com'
>>> str1[:6]
'I love'
>>> str1
'I love fishc.com'
>>> str1[5]
'e'
>>> print(str1[5])
e
>>> str1[:6] + '插入字符串' + str1[6:]
'I love插入字符串 fishc.com'
>>> str1=str1[:6] + '插入字符串' + str1[6:]
>>> str1
'I love插入字符串 fishc.com'
>>> 'e' in str1
True
>>> sum(range(1000,-1000,-2))
1000
>>> sum(range(1000,-1000,-2))
1000
>>> sum(range(1000,-1000,-2))
1000
>>> sum(range(1,5,1))
10
>>> str2 = 'xiaoxie'
>>> str2.capital()
Traceback (most recent call last):
  File "<pyshell#251>", line 1, in <module>
    str2.capital()
AttributeError: 'str' object has no attribute 'capital'
>>> str2.capitalize()
'Xiaoxie'
>>> str2 = 'DAXIExiaoxie'
>>> str2.casefold()
'daxiexiaoxie'
>>> str2
'DAXIExiaoxie'
>>> str2.center(40)
'              DAXIExiaoxie              '
>>> str2.count('xi')
2
>>> str2.endswith('xi')
False
>>> str2.endswith('xie')
True
>>> str3 = 'I\tlove\tFishC.com!'
>>> str.expandtabs()
Traceback (most recent call last):
  File "<pyshell#261>", line 1, in <module>
    str.expandtabs()
TypeError: descriptor 'expandtabs' of 'str' object needs an argument
>>> str3.expandtabs()
'I       love    FishC.com!'
>>> str3.find('efc')
-1
>>> str3.find('com')
13
>>> str4 = '小甲鱼'
>>> str4.islower()
False
>>> str5 = 'FishC'
>>> str5.istitle()
False
>>> str5 = 'Fishc'
>>> str5.istitle()
True
>>> str5.join('12345')
'1Fishc2Fishc3Fishc4Fishc5'
>>> str6 = '     i love you.'
>>> str6.lstrip()
'i love you.'
>>> str6 = 'i love fishc'
>>> str6.partition('ov')
('i l', 'ov', 'e fishc')
>>> str6
'i love fishc'
>>> str6.replace('fishc','fishC')
'i love fishC'
>>> str6
'i love fishc'
>>> str6.split()
['i', 'love', 'fishc']
>>> str6.split('i')
['', ' love f', 'shc']
>>> str7 = '              ssssssaaasss   '
>>> str7.strip()
'ssssssaaasss'
>>> str7
'              ssssssaaasss   '
>>> str7 = str7.strip()
>>> str7.strip('s')
'aaa'
>>> str6
'i love fishc'
>>> str5
'Fishc'
>>> str5.swapcade()
Traceback (most recent call last):
  File "<pyshell#288>", line 1, in <module>
    str5.swapcade()
AttributeError: 'str' object has no attribute 'swapcade'
>>> str5l.swapcase()
Traceback (most recent call last):
  File "<pyshell#289>", line 1, in <module>
    str5l.swapcase()
NameError: name 'str5l' is not defined
>>> str5.swapcase()
'fISHC'
>>> str7
'ssssssaaasss'
>>> str7.translate(str.maketrans('s','b'))
'bbbbbbaaabbb'
>>> str.maketrans('s','b')
{115: 98}
>>> 
