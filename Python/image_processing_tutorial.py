from PIL import Image

src = "image.png"

im = Image.open(src)
im.thumbnail((500, 500))

im_grey = Image.open(src).convert('L')
im_grey.show()

# im.save("image.png")