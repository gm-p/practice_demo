import urllib.request
import os
import random

def url_open(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36')

    proxies = ['14.198.172.81:8088', '37.187.169.69:80', '180.245.157.221:8080','52.77.62.191:80']
    proxy = random.choice(proxies)

    proxy_support = urllib.request.ProxyHandler({'http':proxy})
    opener = urllib.request.build_opener(proxy_support)
    urllib.request.install_opener(opener)

    response = urllib.request.urlopen(req)
    html = response.read()

    #print(url)
    return html

    
def get_page(url):
    html = url_open(url).decode("utf-8")

    a = html.find('current-comment-page') + 23
    b = html.find(']', a)

    return html[a:b]

def find_imgs(url):
    html = url_open(url).decode("utf-8")
    img_addrs = []

    a = html.find('img src=')
    while a != -1:
        b = html.find('.jpg', a, a+255)
        if b != -1:
            img_addrs.append(html[a+9:b+4])
        else:
            b = a + 9

        a = html.find('img src= ', b)
        
    return img_addrs

def save_imgs(folder, img_addrs):
    for each in img_addrs:
        filename = each.split('/')[-1]
        with open(filename, 'wb') as f:
            img = url_open(each)
            f.write(img)

def download_mm(folder='ooxx',page=10):
    os.mkdir(folder)
    os.chdir(folder)

    url = "http://jandan.net/ooxx/"
    page_num = int(get_page(url))

    for i in range(page):
        page_num -= i
        page_url = url + 'page-' + str(page_num) + '#comments'
        img_addrs = find_imgs(page_url)
        save_imgs(folder, img_addrs)

if __name__ == '__main__':
    download_mm()
