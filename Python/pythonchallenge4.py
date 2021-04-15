import urllib.request
import re

search = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing={}"

id_ = "37278"
count = 1

while True:
	doc = str(urllib.request.urlopen(search.format(id_)).read())

	next_id = re.findall("([0-9]+)", doc)
	print(id_)
	if not next_id: 
		print(id_)
		break
	id_ = next_id[0]
	print(count)
	count += 1