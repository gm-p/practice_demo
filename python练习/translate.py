import urllib.request
import urllib.parse
import json
import time

while True:
    content = input("请输入需要翻译的内容(输入'q!'退出程序)：")
    if content == 'q!':
        break

    url = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule&smartresult=ugc&sessionFrom=null"

    '''
    head = {}
    head["User-agent"] = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36'
    '''

    data = {}
    data['type'] = 'AUTO'
    data['i'] = content
    data['doctype'] = 'json'
    data['xmlVersion'] = '1.8'
    data['keyfrom'] =  'fanyi.web'
    data['ue'] = 'UTF-8'
    data['action'] = 'FY_BY_CLICKBUTTON'
    data['typoResult'] = 'true'
    data = urllib.parse.urlencode(data).encode('utf-8')

    req = urllib.request.Request(url, data)   # req = urllib.request.Request(url, data, head)
    req.add_header("User-agent",'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.116 Safari/537.36')
    response = urllib.request.urlopen(req)

    html = response.read().decode('utf-8')

    target = json.loads(html)

    print("翻译结果: %s" % (target['translateResult'][0][0]['tgt']))

    time.sleep(5)
