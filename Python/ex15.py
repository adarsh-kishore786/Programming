from sys import argv

script, filename = argv

txt = open(filename)

print(f"Here's your file {filename}:")
print(txt.read())

print("\nType the filename again:")
file_again = input("> ")

txt_again = open(file_again, 'r+w')

txt_again.seek(0)
txt_again.write("stuff ")

print(txt_again.readline())
