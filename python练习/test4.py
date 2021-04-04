try:
   # int('abc')
    
    f = open('我为什么是一个文件.txt','w')
    print(f.write('我存在了!'))
    sum = 1 + '1'

    ''' 
except OSError as reason:
    print('文件出错了！\n错误的原因是：'+str(reason))
except TypeError as reason:
    print('类型出错了！\n错误的原因是：'+str(reason))  '''
except(OSError, TypeError):
    print('出错了')
finally:
    f.close()
