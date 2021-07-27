import cv2
import numpy as np

img = cv2.imread("image.jpg")

print(type(img))
width, height = img.shape[0:2]

# cv2.imshow("Original", img)
# cv2.waitKey(0)

# Rotating an image
# Syntax: cv2.rotationMatrix(centre, angle, scale)
rotationMatrix = cv2.getRotationMatrix2D((width/2, height/2), 23.5, 0.5)
rotatedImage = cv2.warpAffine(img, rotationMatrix, (width, height))

# cv2.imshow("Rotated", rotatedImage)
# cv2.waitKey(0)

# Cropping an image
startRow = int(height * 0.15)
startCol = int(width * 0.15)

endRow = int(height * 0.85)
endCol = int(width * 0.85)

croppedImage = img[startRow : endRow, startCol : endCol]

# cv2.imshow("Original", img)
# cv2.imshow("Cropped", croppedImage)
# cv2.waitKey(0)

# Resize an image

# Method 1 using scale factors
# resizedImg = cv2.resize(img, (0, 0), fx=0.75, fy=0.75)

# Method 2 using row and col values

resizedImg = cv2.resize(img, (550, 350))

# cv2.imshow("Resized Image", resizedImg)
# cv2.waitKey(0)

# cv2.addWeighted(img1, alpha1, img2, alpha2, beta)
contrast_img = cv2.addWeighted(img, 2.5, np.zeros(img.shape, img.dtype), 0, 0)
cv2.imshow("Contrast", contrast_img)
cv2.waitKey(0)