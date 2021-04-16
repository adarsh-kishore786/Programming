import zipfile36 as zipfile 
import re

src = "channel.zip"
z = zipfile.ZipFile(src, "r")

val = 90052 
src = "channel/{}.txt"

s = ""
while True:
	print(val)
	print(src.format(val))

	with open(src.format(val), "r") as fh:
		data = fh.read()
		vals = re.findall(r"nothing is ([0-9]+)", data)
		print(data)
		s += z.getinfo(str(val) + ".txt").comment.decode()

	if not vals:
		break
	val = vals[0]
print(s)