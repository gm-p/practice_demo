# 对io操作来说，多线程和多进程性能差别不大
# 多线程编程
# 1. 通过Thread类实例化

import threading
import time

def get_detail_html(html):
    print('get detail html started')
    time.sleep(4)
    print('get detail html end')

def get_detail_url(url):
    print('get detail url started')
    time.sleep(4)
    print('get detail url end')

# if __name__ == '__main__':
#     thread1 = threading.Thread(target=get_detail_html, args=('',))
#     thread2 = threading.Thread(target=get_detail_url, args=('',))
#     # thread1.setDaemon(True)  # 设置为守护线程（主线程不用等待守护线程，主线程退出直接杀掉守护线程）
#     # thread2.setDaemon(True)
#     start_time = time.time()
#
#     thread1.start()
#     thread2.start()
#
#     thread1.join()
#     thread2.join()
#
#     # 当主线程退出的时候
#     print('last time: {}'.format(time.time() - start_time))

# 2. 通过继承Thread类来实现多线程
class GetDetailHtml(threading.Thread):
    def __init__(self, name):
        super().__init__(name=name)

    def run(self):
        print('get detail html started')
        time.sleep(4)
        print('get detail html end')


class GetDetailUrl(threading.Thread):
    def __init__(self, name):
        super().__init__(name=name)

    def run(self):
        print('get detail url started')
        time.sleep(4)
        print('get detail url end')

if __name__ == '__main__':
    thread1 = GetDetailHtml('get_detail_html')
    thread2 = GetDetailUrl('get_detail_url')
    start_time = time.time()
    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

    print('last time: {}'.format(time.time() - start_time))