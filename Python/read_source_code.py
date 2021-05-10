"""
read_source_code.py

Shows how we can connect to a website and
read source HTML.
"""

from urllib.request import urlopen
from bs4 import BeautifulSoup

# Fetch html file
response = urlopen("http://www.pythonchallenge.com/pc/def/ocr.html") 	
html_doc = response.read()

# Parse HTML
soup = BeautifulSoup(html_doc, 'html.parser')

# Format the parsed HTML
strhtm = soup.prettify()
n = strhtm.find("-->\n<!--")
m = strhtm.find("*\n-->")

symbol_set = set()
for i in range(n, m+1):
	symbol_set.add(strhtm[i])

symbol_dict = {c : 0 for c in symbol_set}
for i in range(n, m+1):
	if strhtm[i] in symbol_dict.keys():
		symbol_dict[strhtm[i]] += 1

for (key, val) in symbol_dict.items():
	if val == 1:
		print("{0}, ".format(key), end='')

