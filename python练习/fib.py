'''
def fib(n):
    if n == 1:
        return 1
    elif n ==2:
        return 1
    else:
        return fib(n-1) + fib(n-2)

number = int(input('请输入一个正整数:'))
result = fib(number)
print('fib(%d) = %d' % (number, result))
'''
def fib(n):
    if n < 1:
        print('输入错误！')
        return -1

    if n == 1 or n == 2:
        return 1
    else:
        return fib(n-1) + fib(n-2)

result = fib(20)
if result != -1:
    print('总共有%d对小兔子诞生！' % result)
