try:
    print(int('123'))  #int('abc')
except ValueError as reason:
    print('出错啦：'+str(reason))
else:
    print('没有任何异常！')
    
