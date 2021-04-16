
import zipfile36 as zipfile

# WRITING ZIP FILES
# newzip = zipfile.ZipFile("newzip.zip", "w")
# newzip.write("ex15_sample.txt")
# newzip.write("ex16_sample.txt")
# newzip.close()

# # new write will overwrite data
# newzip = zipfile.ZipFile("newzip.zip", "w")
# newzip.write("py3book30.zip")
# newzip.close()

# # data can be appended and will not overwrite
# newzip = zipfile.ZipFile("newzip.zip", "a")
# newzip.write("ex15_sample.txt")
# newzip.write("ex16_sample.txt")
# newzip.close()

# READING THEM
nzip = zipfile.ZipFile("newzip.zip", "r")
data = nzip.read("ex15_sample.txt") # particular file in zip
print(data)

# list all directories in zip, like dir in cmd or ls in Terminal
nzip.printdir()

# extract a particular file from zip in dir
nzip.extract("ex15_sample.txt")#, "newdir")

# extract everything
nzip.extractall("dirall") 

# if no dir mentioned, default dir

# GET INFO
# specific file
print(nzip.getinfo("py3book30.zip"), "\n")

# all files
print(nzip.infolist(), "\n")

# all filenames
print(nzip.namelist(), "\n")
