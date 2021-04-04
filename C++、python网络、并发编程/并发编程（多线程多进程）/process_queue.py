import time
from multiprocessing import Process, Queue, Pool, Manager, Pipe

def producer(queue):
    queue.put('a')
    time.sleep(2)

def consumer(queue):
    time.sleep(2)
    data = queue.get()
    print(data)

# 共享全局变量不能用于多进程编程，可以适用于多线程

# if __name__ == '__main__':
    # queue = Queue(10)
    # my_producer = Process(target=producer, args=(queue,))
    # my_consumer = Process(target=consumer, args=(queue,))
    # my_producer.start()
    # my_consumer.start()
    # my_producer.join()
    # my_consumer.join()


# multiprocessing中的queue不能用于pool进程池
# pool中的进程间通信需要使用manager中的queue
'''3种queue
from queue import Queue
from multiprocessing import Queue
from multiprocessing import Manager
Manager().Queue()
'''
    # queue = Manager().Queue(10)
    # pool = Pool(2)
    # pool.apply_async(producer, args=(queue,))
    # pool.apply_async(consumer, args=(queue,))
    #
    # pool.close()
    # pool.join()

# 通过pipe实现进程间通信(只能用于两个进程间通信)
# pipe的性能高于queue
# def producer(pipe):
#     pipe.send('bobby')
#
# def consumer(pipe):
#     print(pipe.recv())
#
# if __name__ == '__main__':
#     recv_pipe, send_pipe = Pipe()
#     my_producer = Process(target=producer, args=(send_pipe,))
#     my_consumer = Process(target=consumer, args=(recv_pipe,))
#
#     my_producer.start()
#     my_consumer.start()
#     my_producer.join()
#     my_consumer.join()

# 共享内存
def add_data(p_dict, key, value):
    p_dict[key] = value

if __name__ == '__main__':
    process_dict = Manager().dict()

    first_process = Process(target=add_data, args=(process_dict, 'bobby1', 22))
    second_process = Process(target=add_data, args=(process_dict, 'bobby2', 23))
    first_process.start()
    second_process.start()
    first_process.join()
    second_process.join()

    print(process_dict)