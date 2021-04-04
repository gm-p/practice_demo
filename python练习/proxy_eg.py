import urllib.request
import random

url = "http://www.whatismyip.com.tw"

iplist = ['182.101.221.96:9000', '115.218.122.0:9000', '106.6.248.146:8090']

#proxy_support = urllib.request.ProxyHandler({'http':random.choice(iplist)})
proxy_support = urllib.request.ProxyHandler({'http':'115.218.217.59:9000'})

opener = urllib.request.build_opener(proxy_support)
opener.addheaders = [('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36')]

urllib.request.install_opener(opener)

response = urllib.request.urlopen(url)

html = response.read().decode("utf-8")

print(html)
