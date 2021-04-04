# 使用多线程：在协程中集成阻塞IO
import asyncio


if __name__ == '__main__':
    import time
    start_time = time.time()
    loop = asyncio.get_event_loop()
    executor = ThreadPoolExecutor()
    tasks = []
    for url in range(20):
        url = 'http://shop.projectsedu.com/goods/{}/'.format(url)
        task = loop.run_in_executor(executor, get_url, url)
        tasks.append(task)
    loop.run_until_complete(asyncio.wait(tasks))
    print('last time: {}'.format(time.time() - start_time))