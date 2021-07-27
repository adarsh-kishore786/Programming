import urllib.request
import pickle 

url = "http://www.pythonchallenge.com/pc/def/banner.p"

urllib.request.urlretrieve(url, filename="pythonchallenge5.pkl")

with open("pythonchallenge5.pkl", "rb") as data:
	emp = pickle.load(data)

d = []
for e in emp:
	for f in e:
		print(f[0] * f[1], end='')
	print()