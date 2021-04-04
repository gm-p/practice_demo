Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 19:28:18) [MSC v.1600 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> 
================== RESTART: C:\Users\asus\Desktop\pytest.py ==================
Traceback (most recent call last):
  File "C:\Users\asus\Desktop\pytest.py", line 38, in <module>
    save_file(boy,girl,count)
NameError: name 'boy' is not defined
>>> 
================== RESTART: C:\Users\asus\Desktop\pytest.py ==================
Traceback (most recent call last):
  File "C:\Users\asus\Desktop\pytest.py", line 38, in <module>
    save_file(boy,girl,count)
NameError: name 'boy' is not defined
>>> def save_file(boy, girl, count):
	boy_file_name = 'boy_' + str(count) + '.txt'
	girl_file_name = 'girl_' +str(count) + '.txt'

	boy_file = open(boy_file_name, 'w')
	girl_file = open(girl_file_name, 'w')

	boy_file.writeliens(boy)
	girl_file.writelines(girl)

	boy_file.close()
	girl_file.close()

def split_file(filename):
	f = open(filename)

	boy = []
	girl = []
	count = 1

	for each_lines in f:
		if each_lines[:6] != '======':
			(role, spoken) = each_lines.split(':',1)

			if role == '小甲鱼':
				boy.append(spoken)

			if role == '小客服':
				girl.append(spoken)

		else:
			save_file(boy, girl, count)

			count += 1
			boy = []
			girl = []

save_file(boy,girl,count)

split_file('D:/python练习/record.txt')
SyntaxError: invalid syntax
>>> 
def save_file(boy, girl, count):
	boy_file_name = 'boy_' + str(count) + '.txt'
	girl_file_name = 'girl_' +str(count) + '.txt'

	boy_file = open(boy_file_name, 'w')
	girl_file = open(girl_file_name, 'w')

	boy_file.writeliens(boy)
	girl_file.writelines(girl)

	boy_file.close()
	girl_file.close()

def split_file(filename):
	f = open(filename)

	boy = []
	girl = []
	count = 1

	for each_lines in f:
		if each_lines[:6] != '======':
			(role, spoken) = each_lines.split(':',1)

			if role == '小甲鱼':
				boy.append(spoken)

			if role == '小客服':
				girl.append(spoken)

		else:
			save_file(boy, girl, count)

			count += 1
			boy = []
			girl = []

save_file(boy,girl,count)

split_file('D:/python练习/record.txt')
SyntaxError: invalid syntax
>>> 
================== RESTART: C:\Users\asus\Desktop\pytest.py ==================
Traceback (most recent call last):
  File "C:\Users\asus\Desktop\pytest.py", line 38, in <module>
    save_file(boy,girl,count)
NameError: name 'boy' is not defined
>>> 
================== RESTART: C:\Users\asus\Desktop\pytest.py ==================
Traceback (most recent call last):
  File "C:\Users\asus\Desktop\pytest.py", line 41, in <module>
    split_file('D:/python练习/record.txt')
  File "C:\Users\asus\Desktop\pytest.py", line 32, in split_file
    save_file(boy, girl, count)
  File "C:\Users\asus\Desktop\pytest.py", line 8, in save_file
    boy_file.writeliens(boy)
AttributeError: '_io.TextIOWrapper' object has no attribute 'writeliens'
>>> 
================== RESTART: C:\Users\asus\Desktop\pytest.py ==================
>>> 
>>> 
