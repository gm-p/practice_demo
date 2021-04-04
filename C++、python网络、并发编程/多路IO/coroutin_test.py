# 协程：有多个入口的函数，可以暂停的函数(可以向暂停的地方传入值)

def gen_func():
    # 1.可以产出值， 2.可以接收值(调用方传递进来的值)
    html = yield "http://projectsedu.com"
    print(html)
    return "bobby"

# 1. 生成器不只可以产出值，还可以接收值
if __name__ == '__main__':
    gen = gen_func()
    # 在调用send发送非None值之前，必须启动一次生成器，方式有两种：1.gen.send(None) 2.next(gen)
    # url = gen.send(None)
    url = next(gen)  # 启动生成器的方式有两种：next(), send
    html = "bobby"
    print(gen.send(html))  # send可以传递值进入生成器内部，同时还可以重启生成器执行到下一个执行的yield位置