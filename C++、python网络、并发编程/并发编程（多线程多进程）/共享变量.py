# 线程间通信

import time
import threading
import variables

detail_url_list = []

def get_detail_html():
    # 爬取文章详情页
    detail_url_list = variables.detail_url_list
    while True:
        if len(detail_url_list):
            url = detail_url_list.pop()
            # for url in detail_url_list:
            print('get detail html started')
            time.sleep(2)
            print('get detail html end')

def get_detail_url():
    # 爬取文章列表页
    detail_url_list = variables.detail_url_list
    while True:
        print('get detail url started')
        time.sleep(4)
        for i in range(20):
            detail_url_list.append('http://projectsedu.com/{id}'.format(id=i))
        print('get detail url end')

if __name__ == '__main__':
    thread1 = threading.Thread(target=get_detail_url)
    start_time = time.time()
    for i in range(10):
        thread = threading.Thread(target=get_detail_html)
        thread.join()
    print('last time: {}'.format(time.time() - start_time))