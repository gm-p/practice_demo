def hanio(n, x, y, z):
    if n == 1:
        print(x,'-->',z)
        global count
        count += 1
    else:
        hanio(n-1, x, z, y) #将n-1个盘子从x移动到y上
        print(x, '-->', z)  #将最底下的最后一个盘子从x移动到z上
        #global count
        count += 1
        hanio(n-1, y, x, z) #将y上的n-1个盘子移动到x上

n = int(input('请输入汉诺塔的层数：'))
count=0
hanio(n,'X','Y','Z')
print('总共移动步数为:%d' % count)
