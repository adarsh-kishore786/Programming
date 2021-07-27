from sys import argv

script, filename = argv

print(f"We are going to erase {filename}.")
print("If you don't want that, hit CTRL-C (^C).")
print("If you do want that, hit ENTER.")

input("?")

print("Opening the file...")
target = open(filename, 'w')

print("Truncating the file. Goodbye!")
print("Now I'm going to ask you for three lines.")

line = []

for i in range(3):
	line.append(input(f"line {i}: "))

print("I\'m going to write these to the file.")

for i in range(3):
	target.write((line[i] + '\n'))

print("And finally, we close it.")
target.close()