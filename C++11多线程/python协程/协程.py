# run_until_complete()
import asyncio


async def func(future):
    await asyncio.sleep(1)
    future.set_result('Future is donw!')


class Student(object):

    @property
    def score(self):   # @property 装饰器负责把一个方法变成一个属性调用
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100')
        self._score = value

    @property
    def birth(self):   # birth是可读写属性
        return self._birth

    @birth.setter
    def birth(self, value):
        self._birth = value

    @property
    def age(self):      # age是只读属性
        return 2020 - self._birth


if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    future = asyncio.Future()
    asyncio.ensure_future(func(future))
    print(loop.is_running())
    loop.run_until_complete(future)
    print(future.result())
    loop.close()

    # s = Student()
    # s.score = 60
    # print(s.score)
    # # s.score = 9999
    # s.birth = 2002
    # print(s.age)


# run_forever()
# import asyncio
#
#
# async def func(future):
#     await asyncio.sleep(1)
#     future.set_result('Future is done!')
#
#
# def call_result(future):
#     print(future.result())
#     loop.stop()
#
#
# if __name__ == '__main__':
#     loop = asyncio.get_event_loop()
#     future = asyncio.Future()
#     asyncio.ensure_future(func(future))
#     future.add_done_callback(call_result)
#     try:
#         loop.run_forever()
#     finally:
#         loop.close()

# https://www.yuque.com/keep_running/python/gpvth4