import re
from urllib.request import urlopen
from bs4 import BeautifulSoup

response = urlopen("http://www.pythonchallenge.com/pc/def/equality.html")
html = response.read()

soup = BeautifulSoup(html, "html.parser")

word = re.findall("[^A-Z]+[A-Z]{3}([a-z])[A-Z]{3}[^A-Z]+", str(soup))
print(word)