import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from concurrent.futures import ProcessPoolExecutor


def fib(n):
    if n <= 2:
        return 1
    return fib(n-1) + fib(n-2)

if __name__ == '__main__':
    # with ThreadPoolExecutor(3) as executor:  # 多线程
    with ProcessPoolExecutor(3) as executor:  # 多进程
        all_task = [executor.submit(fib, (num)) for num in range(25, 35)]
        start_time = time.time()
        for future in as_completed(all_task):
            data = future.result()
            print('exe result: {}'.format(data))

        print('last time is: {}'.format(time.time() - start_time))