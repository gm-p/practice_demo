import urllib.request

#response = urllib.request.urlopen("http://placekitten.com/g/500/600")
req = urllib.request.Request("http://placekitten.com/g/500/600")
response = urllib.request.urlopen(req)

cat_img = response.read()

with open("cat_500_600.jpg", 'wb') as f:
    f.write(cat_img)
