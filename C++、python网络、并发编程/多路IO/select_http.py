# epoll 并不代表一定比select好
# 在并发高的情况下，连接活跃度不是很高，epoll比select好
# 并发性不高，同时连接很活跃，select比epoll好

# 通过非阻塞IO实现http请求
import socket
from urllib.parse import urlparse
from selectors import DefaultSelector, EVENT_READ, EVENT_WRITE

# 使用select完成http请求
selector = DefaultSelector()
urls = ['http://www.baidu.com']
stop = False

class Fetcher:
    def connected(self, key):
        selector.unregister(key.fd)
        self.client.send("GET {} HTTP/1.1\r\nHost:{}\r\nConnection:close\r\n\r\n".format(self.path, self.host).encode('utf-8'))
        selector.register(self.client.fileno(), EVENT_READ, self.readable)

    def readable(self, key):
        d = self.client.recv(1024)
        if d:
            self.data += d
        else:
            selector.unregister(key.fd)
            data = self.data.decode('utf-8')
            html_data = data.split('\r\n\r\n')[1]
            print(html_data)
            self.client.close()
            urls.remove(self.spider_url)
            if not urls:
                global stop
                stop = True

    def get_url(self, url):
        self.spider_url = url
        url = urlparse(url)
        self.host = url.netloc
        self.path = url.path
        if self.path == "":
            self.path = "/"

        self.data = b""
        # 建立socket连接
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.setblocking(False)
        try:
            self.client.connect((self.host, 80))
        except BlockingIOError as e:
            pass

        # 注册
        selector.register(self.client.fileno(), EVENT_WRITE, self.connected)  # 回调

def loop():
    # 事件循环，不停的请求socket的状态并调用对应的回调函数
    # 1. select本身是不支持register模式
    # 2. socket状态变化以后的回调是由程序员完成的
    while not stop:
        ready = selector.select()
        for key, mask in ready:
            call_back = key.data
            call_back(key)
    # 回调 + 事件循环 + select(poll/epoll)

if __name__ == '__main__':
    fetcher = Fetcher()
    fetcher.get_url('http://www.baidu.com')
    loop()

# def get_url(url):
#     # 通过socket请求html
#     url = urlparse(url)
#     host = url.netloc
#     path = url.path
#     if path == "":
#         path = "/"
#
#     # 建立socket连接
#     client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#     client.setblocking(False) # 非阻塞
#     try:
#         client.connect((host, 80))  # 阻塞不会消耗cpu
#     except BlockingIOError as e:
#         pass
#
#     # 不停的询问连接是否建立好，需要while循环不停的检查状态
#     # 做计算任务或者再次发起其他的连接
#
#     while True:
#         try:
#             client.send("GET {} HTTP/1.1\r\nHost:{}\r\nConnection:close\r\n\r\n".format(path, host).encode('utf-8'))
#             break
#         except OSError as e:
#             pass
#
#     data = b""
#     while True:
#         try:
#             d = client.recv(1024)
#         except BlockingIOError as e:
#             continue
#         if d:
#             data += d
#         else:
#             break
#     data = data.decode('utf-8')
#     html_data = data.split('\r\n\r\n')[1]
#     print(html_data)
#     client.close()


