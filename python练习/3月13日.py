Python 3.4.4 (v3.4.4:737efcadf5a6, Dec 20 2015, 19:28:18) [MSC v.1600 32 bit (Intel)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> import re
>>> re.search(r'FishC', 'I love FishC.com!')
<_sre.SRE_Match object; span=(7, 12), match='FishC'>
>>> "I love FishC.com".find('FishC')
7
>>> re.search(r'.', 'I love FishC.com!')
<_sre.SRE_Match object; span=(0, 1), match='I'>
>>> re.search(r'Fish.', 'I love FishC.com!')
<_sre.SRE_Match object; span=(7, 12), match='FishC'>
>>> re.search(r'\.', 'I love FishC.com!')
<_sre.SRE_Match object; span=(12, 13), match='.'>
>>> 
>>> re.search(r'\d', 'I love 123 FishC.com!')
<_sre.SRE_Match object; span=(7, 8), match='1'>
>>> re.search(r'\d\d\d', 'I love 123 FishC.com!')
<_sre.SRE_Match object; span=(7, 10), match='123'>
>>> re.search(r'\d\d\d.\d\d\d.\d\d\d.\d\d\d', '192.168.111.123')
<_sre.SRE_Match object; span=(0, 15), match='192.168.111.123'>
>>> re.search(r'[aeiou]', 'I love FishC.com!')
<_sre.SRE_Match object; span=(3, 4), match='o'>
>>> re.search(r'[aeiouAEIOU]', 'I love FishC.com!')
<_sre.SRE_Match object; span=(0, 1), match='I'>
>>> re.search(r'[a-z]', 'I love FishC.com!')
<_sre.SRE_Match object; span=(2, 3), match='l'>
>>> re.search(r'[0-9]', 'I love 123 FishC.com!')
<_sre.SRE_Match object; span=(7, 8), match='1'>
>>> re.search(r'[2-9]', 'I love 123 FishC.com!')
<_sre.SRE_Match object; span=(8, 9), match='2'>
>>> re.search(r'ab{3}c', 'abbbc')
<_sre.SRE_Match object; span=(0, 5), match='abbbc'>
>>> re.search(r'ab{3,10}c', 'abbbbbbc')
<_sre.SRE_Match object; span=(0, 8), match='abbbbbbc'>
>>> re.search('[01]\d\d|2[0-4]\d|25[0-5]', '188')
<_sre.SRE_Match object; span=(0, 3), match='188'>
>>> re.search(r'(([01]\d\d|2[0-4]\d|25[0-5])\.){3}([01]\d\d|2[0-4]\d|25[0-5])','192.168.1.1')
>>> re.search(r'(([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])\.){3}([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])','192.168.1.1')<_sre.SRE_Match object; span=(0, 3), match='188'>
SyntaxError: invalid syntax
>>> re.search(r'(([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])\.){3}([01]{0,1}\d{0,1}\d|2[0-4]\d|25[0-5])','192.168.1.1')
<_sre.SRE_Match object; span=(0, 11), match='192.168.1.1'>
>>> import re
>>> re.search(r'FishC|D', 'FishC')
<_sre.SRE_Match object; span=(0, 5), match='FishC'>
>>> re.search(r'FishC|D', 'FishD')
<_sre.SRE_Match object; span=(4, 5), match='D'>
>>> re.search(r'Fish(C|D)', 'FishD')
<_sre.SRE_Match object; span=(0, 5), match='FishD'>
>>> re.search(r"^FishC", "I love FishC.com" )
>>> re.search(r"^FishC", "FishC.com" )
<_sre.SRE_Match object; span=(0, 5), match='FishC'>
>>> re.search(r"FishC$", "FishC.com" )
>>> re.search(r"FishC$", "love FishC" )
<_sre.SRE_Match object; span=(5, 10), match='FishC'>
>>> re.search(r"(FishC)\1", "love FishC" )
>>> re.search(r"(FishC)\1", "FishCFishC" )
<_sre.SRE_Match object; span=(0, 10), match='FishCFishC'>
>>> re.search(r'(FishC)\060', 'FishCFishC')
>>> re.search(r'(FishC)\060', 'FishCFishC0')
<_sre.SRE_Match object; span=(5, 11), match='FishC0'>
>>> re.search(r'(FishC)\141', 'FishCFishC0')
>>> re.search(r'(FishC)\141', 'FishCFishCa')
<_sre.SRE_Match object; span=(5, 11), match='FishCa'>
>>> re.search(r'.', 'FishCFishCa')
<_sre.SRE_Match object; span=(0, 1), match='F'>
>>> re.search(r'\.', 'FishCFishCa')
>>> re.search(r'[.]', 'FishCFish.com')
<_sre.SRE_Match object; span=(9, 10), match='.'>
>>> re.findall(r'[a-z]', 'FishC.com')
['i', 's', 'h', 'c', 'o', 'm']
>>> re.findall(r'[\]', 'FishC.com')
Traceback (most recent call last):
  File "<pyshell#39>", line 1, in <module>
    re.findall(r'[\]', 'FishC.com')
  File "D:\Program Files (x86)\Python\lib\re.py", line 210, in findall
    return _compile(pattern, flags).findall(string)
  File "D:\Program Files (x86)\Python\lib\re.py", line 294, in _compile
    p = sre_compile.compile(pattern, flags)
  File "D:\Program Files (x86)\Python\lib\sre_compile.py", line 568, in compile
    p = sre_parse.parse(p, flags)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 780, in parse
    p = _parse_sub(source, pattern, 0)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 377, in _parse_sub
    itemsappend(_parse(source, state))
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 503, in _parse
    raise error("unexpected end of regular expression")
sre_constants.error: unexpected end of regular expression
>>> re.findall(r'[\n]', 'FishC.com\n')
['\n']
>>> re.findall(r'[^a-z]', 'FishC.com\n')
['F', 'C', '.', '\n']
>>> re.findall(r'[a-z^]', 'FishC.com\n')
['i', 's', 'h', 'c', 'o', 'm']
>>> re.findall(r'[a-z^]', '^FishC.com\n')
['^', 'i', 's', 'h', 'c', 'o', 'm']
>>> re.search(r"FishC{3}", "FishCCCCCC")
<_sre.SRE_Match object; span=(0, 7), match='FishCCC'>
>>> re.search(r"(FishC){3}", "FishCFishCFishCCCC")
<_sre.SRE_Match object; span=(0, 15), match='FishCFishCFishC'>
>>> re.search(r"(FishC){1,5}", "FishCFishCFishC")
<_sre.SRE_Match object; span=(0, 15), match='FishCFishCFishC'>
>>> a = "<html><title>I love FishC.com</title></html>"
>>> re.search(r"<.+>", a)
<_sre.SRE_Match object; span=(0, 44), match='<html><title>I love FishC.com</title></html>'>
>>> re.search(r"<.+?>", a)
<_sre.SRE_Match object; span=(0, 6), match='<html>'>
>>> import re
>>> re.findall(r"\bfishC\b", "fishC.com!fishC_com!(FishC)")
['fishC']
>>> re.findall(r"\bfishC\b", "fishC.com!fishC_com!(fishC)")
['fishC', 'fishC']
>>> re.findall(r"\w", "我爱鱼C工作室（love_FishC.com!）")
['我', '爱', '鱼', 'C', '工', '作', '室', 'l', 'o', 'v', 'e', '_', 'F', 'i', 's', 'h', 'C', 'c', 'o', 'm']
>>> p = re.compile(r"[A-Z]")
>>> type(p)
<class '_sre.SRE_Pattern'>
>>> p.search("I love FishC.com!")
<_sre.SRE_Match object; span=(0, 1), match='I'>
>>> p.findall("I love FishC.com!")
['I', 'F', 'C']
>>> import re
>>> re.search(r" (\w+) (\w+)", "I love FishC.com!")
<_sre.SRE_Match object; span=(1, 12), match=' love FishC'>
>>> result = re.search(r" (\w+) (\w+)", "I love FishC.com!")
>>> result
<_sre.SRE_Match object; span=(1, 12), match=' love FishC'>
>>> result.group()
' love FishC'
>>> result.group(1)
'love'
>>> result.group(2)
'FishC'
>>> result.start()
1
>>> result.end()
12
>>> result.span()
(1, 12)
>>> 
======================= RESTART: D:/python练习/tieba.py =======================
Traceback (most recent call last):
  File "D:/python练习/tieba.py", line 22, in <module>
    get_img(open_url(url))
  File "D:/python练习/tieba.py", line 14, in get_img
    imglist = re.findall(p, html)
  File "D:\Program Files (x86)\Python\lib\re.py", line 210, in findall
    return _compile(pattern, flags).findall(string)
  File "D:\Program Files (x86)\Python\lib\re.py", line 294, in _compile
    p = sre_compile.compile(pattern, flags)
  File "D:\Program Files (x86)\Python\lib\sre_compile.py", line 568, in compile
    p = sre_parse.parse(p, flags)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 780, in parse
    p = _parse_sub(source, pattern, 0)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 377, in _parse_sub
    itemsappend(_parse(source, state))
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 588, in _parse
    raise error("multiple repeat")
sre_constants.error: multiple repeat
>>> 
======================= RESTART: D:/python练习/tieba.py =======================
Traceback (most recent call last):
  File "D:/python练习/tieba.py", line 22, in <module>
    get_img(open_url(url))
  File "D:/python练习/tieba.py", line 14, in get_img
    imglist = re.findall(p, html)
  File "D:\Program Files (x86)\Python\lib\re.py", line 210, in findall
    return _compile(pattern, flags).findall(string)
  File "D:\Program Files (x86)\Python\lib\re.py", line 294, in _compile
    p = sre_compile.compile(pattern, flags)
  File "D:\Program Files (x86)\Python\lib\sre_compile.py", line 568, in compile
    p = sre_parse.parse(p, flags)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 780, in parse
    p = _parse_sub(source, pattern, 0)
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 377, in _parse_sub
    itemsappend(_parse(source, state))
  File "D:\Program Files (x86)\Python\lib\sre_parse.py", line 588, in _parse
    raise error("multiple repeat")
sre_constants.error: multiple repeat
>>> 
======================= RESTART: D:/python练习/tieba.py =======================
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=aa042893d558ccbf1bbcb53229d9bcd4/82e96d600c338744f222ae5d550fd9f9d62aa07d.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=eb662d34b8315c6043956be7bdb0cbe6/3b8726a4462309f79bca2c33760e0cf3d6cad6b3.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=20882c33760e0cf3a0f74ef33a47f23d/7de9ad18972bd407852052dc7f899e510eb3097d.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=9ded1bd27d310a55c424defc87444387/94339f25bc315c605e73eace89b1cb134854777e.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=1a4335da3ddbb6fd255be52e3925aba6/08148b1001e939016aa60c1f7fec54e737d196bc.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=ab26e52c229759ee4a5060c382fa434e/d00f7b1ed21b0ef4b809197fd9c451da80cb3e7f.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=aba74ccdd500baa1ba2c47b37711b9b1/278efdf2b211931384e47e9161380cd790238dbd.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=c8779a628fd4b31cf03c94b3b7d7276f/f646a01ea8d3fd1fc3ae231b344e251f94ca5fbd.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=b056cf989a510fb37819779fe932c893/ef9d49c2d5628535b346530094ef76c6a6ef63be.jpg"
<img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=f37ab72a5fb5c9ea62f303ebe538b622/77827ef0f736afc3bed0be44b719ebc4b6451204.jpg"
<img class="BDE_Image" src="http://tb1.bdstatic.com/tb/cms/ngmis/adsense/file_1457575250038.jpg"
>>> 
======================= RESTART: D:/python练习/tieba.py =======================
http://imgsrc.baidu.com/forum/w%3D580/sign=aa042893d558ccbf1bbcb53229d9bcd4/82e96d600c338744f222ae5d550fd9f9d62aa07d.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=eb662d34b8315c6043956be7bdb0cbe6/3b8726a4462309f79bca2c33760e0cf3d6cad6b3.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=20882c33760e0cf3a0f74ef33a47f23d/7de9ad18972bd407852052dc7f899e510eb3097d.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=9ded1bd27d310a55c424defc87444387/94339f25bc315c605e73eace89b1cb134854777e.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=1a4335da3ddbb6fd255be52e3925aba6/08148b1001e939016aa60c1f7fec54e737d196bc.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=ab26e52c229759ee4a5060c382fa434e/d00f7b1ed21b0ef4b809197fd9c451da80cb3e7f.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=aba74ccdd500baa1ba2c47b37711b9b1/278efdf2b211931384e47e9161380cd790238dbd.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=c8779a628fd4b31cf03c94b3b7d7276f/f646a01ea8d3fd1fc3ae231b344e251f94ca5fbd.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=b056cf989a510fb37819779fe932c893/ef9d49c2d5628535b346530094ef76c6a6ef63be.jpg
http://imgsrc.baidu.com/forum/w%3D580/sign=f37ab72a5fb5c9ea62f303ebe538b622/77827ef0f736afc3bed0be44b719ebc4b6451204.jpg
http://tb1.bdstatic.com/tb/cms/ngmis/adsense/file_1457575250038.jpg
>>> 
======================= RESTART: D:/python练习/tieba.py =======================
>>> 
======================= RESTART: D:/python练习/getIP.py =======================
Traceback (most recent call last):
  File "D:/python练习/getIP.py", line 24, in <module>
    get_img(open_url(url))
  File "D:/python练习/getIP.py", line 19, in get_img
    for each in iplist:
NameError: name 'iplist' is not defined
>>> 
======================= RESTART: D:/python练习/getIP.py =======================
>>> 
======================= RESTART: D:/python练习/getIP.py =======================
('9.', '9', '102')
('9.', '9', '102')
>>> 
======================= RESTART: D:/python练习/getIP.py =======================
1.1.9.102
1.1.9.102
>>> import urllib.request
>>> import urllib.error
>>> req = urllib.request.Request("http://www.ooxx-fishc.com")
>>> try:
	urllib.request.urlopen(req)
except urllib.error.URLError as e:
	print(e.reason)

	
[Errno 11004] getaddrinfo failed
>>> req  =  urllib.request.Request("http://www.fishc.com/ooxx.html")
>>> try:
	urllib.request.urlopen(req)
except urllib.error.HTTPError as e:
	print(e.code)
	print(e.read())

	
404
b'<?xml version="1.0" encoding="ISO-8859-1"?>\n<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"\n  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">\n<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">\n<head>\n<title>Object not found!</title>\n<link rev="made" href="mailto:webmaster@example.com" />\n<style type="text/css"><!--/*--><![CDATA[/*><!--*/ \n    body { color: #000000; background-color: #FFFFFF; }\n    a:link { color: #0000CC; }\n    p, address {margin-left: 3em;}\n    span {font-size: smaller;}\n/*]]>*/--></style>\n</head>\n\n<body>\n<h1>Object not found!</h1>\n<p>\n\n\n    The requested URL was not found on this server.\n\n  \n\n    If you entered the URL manually please check your\n    spelling and try again.\n\n  \n\n</p>\n<p>\nIf you think this is a server error, please contact\nthe <a href="mailto:webmaster@example.com">webmaster</a>.\n\n</p>\n\n<h2>Error 404</h2>\n<address>\n  <a href="/">www.fishc.com</a><br />\n  \n  <span>Sun Mar 13 16:50:42 2016<br />\n  Apache</span>\n</address>\n</body>\n</html>\n\n'
>>> 
======================== RESTART: D:/python练习/tk1.py ========================
>>> 
======================== RESTART: D:/python练习/tk1.py ========================
>>> 
======================== RESTART: D:/python练习/tk2.py ========================
>>> 
======================== RESTART: D:/python练习/tk2.py ========================
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
>>> 
======================== RESTART: D:/python练习/tk2.py ========================
>>> 
======================== RESTART: D:/python练习/tk2.py ========================
>>> 
======================== RESTART: D:/python练习/tk2.py ========================
互联网的广大朋友们大家好，我是小甲鱼！
互联网的广大朋友们大家好，我是小甲鱼！
>>> 
======================== RESTART: D:/python练习/tk1.py ========================
>>> 
