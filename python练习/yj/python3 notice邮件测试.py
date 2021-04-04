import requests
import json

to, sub, content = 'guangming.pan@envision-energy.com', '测试', 'Python3 邮件测试'
mail = {}
mail['to'] = to
mail['subject'] = sub
mail['content'] = content
requests.post('http://notice.eniot.io/api/mail?token=9BzmWuy93rcliUOdMcfhcaeN8HLUaUgr', data=json.dumps(mail))# headers={'content-type': 'application/json'}