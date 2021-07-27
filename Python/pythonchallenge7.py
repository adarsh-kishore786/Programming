import cv2
import sys
import numpy as np
import re
np.set_printoptions(threshold=sys.maxsize)

img = cv2.imread("oxygen.png")
width = img.shape[0]

pixels = np.array([p for p in img[width//2] if p[0] == p[1] == p[2]])

s = ""
for i in range(0, len(pixels), 7):
	p = pixels[i]
	if p[0] == p[1] == p[2]:
		s += chr(p[0])

z = re.findall(r"[0-9]{1,3}", s)
num = [int(e) for e in z]
print(num)

print([chr(e) for e in num])