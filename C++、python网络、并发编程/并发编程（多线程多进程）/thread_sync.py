# gil global interpreter lock(cpython)
# python 同一个线程对应于C语言的一个线程
# gil使得同一个时刻只有一个线程在一个cpu上执行字节码，无法将多个线程映射到多个cpu上执行

# gis会根据执行的字节码行数以及时间片释放gil，gil在遇到io操作时候主动释放
# import dis
# def add(a):
#     a = a + 1
#     return a
#
# print(dis.dis(add))  # 打印字节码

from threading import Lock, RLock  # RLock可重入锁

# 1.用锁会影响性能
# 2.锁会引起死锁
lock = RLock() # 同一个线程可以多次acquire#Lock()
total = 0

def add():
    global total
    global lock
    for _ in range(1000000):
        lock.acquire()
        lock.acquire()
        total += 1
        lock.release()
        lock.release()

def desc():
    global total
    global lock
    for _ in range(1000000):
        lock.acquire()
        total -= 1
        lock.release()

import threading
thread1 = threading.Thread(target=add)
thread2 = threading.Thread(target=desc)
thread1.start()
thread2.start()

thread1.join()
thread2.join()

print(total)