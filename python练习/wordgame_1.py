"""print('--------------------我爱鱼C工作室---------------------')
temp=input("不妨猜一下小甲鱼现在心里想的是哪个数字：")
guess=int(temp)
if guess==8:
    print("我草，你是小甲鱼心里的蛔虫吗？！")
    print("哼，猜中了也没有奖励！")
else:
    print("猜错啦，小甲鱼现在心里想的是8！")
print("游戏结束，不玩啦^_^")"""

"""
print('--------------------我爱鱼C工作室---------------------')
while 1:
    temp=input("不妨猜一下小甲鱼现在心里想的是哪个数字：")
    guess=int(temp)
    if guess==8:
        print("我草，你是小甲鱼心里的蛔虫吗？！")
        print("哼，猜中了也没有奖励！")
    elif guess>8:
        print("猜错啦，大了！")
    else:
        print("猜错了，小了！")
print("游戏结束，不玩啦^_^")
"""

import random
secret=random.randint(1,10)
print('---------我是小甲鱼工作室-----------')
temp=input("不妨猜一下小甲鱼现在现在心里想的是哪个数字：")
guess=int(temp)
#count=1
while guess!=secret:
    temp=input("哎呀，猜错了，请重新输入吧：")
    guess=int(temp)
    if guess==8:
        print("我草，你是小甲鱼心里的蛔虫吗？")
        print("哼，猜中了也没有奖励")
    else:
        if guess>8:
            print("哥，大了大了~~")
        else:
            print("嘿，小了，小了！！")
    #count=count+1
    #print(count)
print("游戏结束，不玩啦~~")
