file_name = input('请输入需要打开的文件名：')
f = open(file_name)
print('文件的内容是：')
for each_lines in f:
    print(each_lines)
