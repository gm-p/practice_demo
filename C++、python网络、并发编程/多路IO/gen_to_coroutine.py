# 生成器是可以暂停的函数
import inspect

def gen_func():
    value = yield 1  # 第一返回值给调用方，第二调用方通过send方式返回值给gen
    return 'bobby'

if __name__ == '__main__':
    gen = gen_func()
    print(inspect.getgeneratorstate(gen))
    next(gen)
    print(inspect.getgeneratorstate(gen))
    try:
        next(gen)
    except StopIteration:
        pass
    print(inspect.getgeneratorstate(gen))