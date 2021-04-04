# 线程间通信

import time
import threading
import variables
from queue import Queue


def get_detail_html(queue):
    # 爬取文章详情页
    while True:
        url = queue.get()
        # for url in detail_url_list:
        print('get detail html started')
        time.sleep(2)
        print('get detail html end')

def get_detail_url(queue):
    # 爬取文章列表页
    while True:
        print('get detail url started')
        time.sleep(4)
        for i in range(20):
            queue.put('http://projectsedu.com/{id}'.format(id=i))
        print('get detail url end')

if __name__ == '__main__':
    detail_url_queue = Queue(maxsize=1000)

    thread1 = threading.Thread(target=get_detail_url)
    start_time = time.time()
    for i in range(10):
        thread = threading.Thread(target=get_detail_html)
        thread.join()

    detail_url_queue.task_done()
    detail_url_queue.join()
    print('last time: {}'.format(time.time() - start_time))