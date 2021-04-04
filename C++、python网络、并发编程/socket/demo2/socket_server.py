import socket
import threading

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('0.0.0.0', 8000))
server.listen()
# sock, addr = server.accept()

def handle_sock(sock, addr):
    while True:
        data = sock.recv(1024)
        print(data.decode('utf8'))
        msg = input()
        sock.send(msg.encode('utf8'))
    # sock.close()
# 获取从客户端发送的数据
# 一次获取1k的数据
# data = sock.recv(1024)
# print(data.decode('utf8'))
# sock.send('Hello {}'.format(data.decode('utf8')).encode('utf8'))
while True:
    sock, addr = server.accept()
    thread_sock = threading.Thread(target=handle_sock, args=(sock, addr))
    thread_sock.start()
server.close()
sock.close()