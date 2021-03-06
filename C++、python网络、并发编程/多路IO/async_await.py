# python为了将语义变得更加明确，就引入了async和await关键字用于定义原生的协程
async def downloader(url):
    return 'bobby'

# import types
# @types.coroutine
# def downloader(url):
#     yield 'bobby'

async def download_url(url):
    # do somethings
    html = await downloader(url)
    return html

if __name__ == '__main__':
    coro = download_url('http://www.imooc.com')
    coro.send(None)  # 不能用next(None)
