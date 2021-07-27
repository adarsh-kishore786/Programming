from sys import argv

script, input_file = argv

def print_all(f):
	print(f.read())

def rewind(f):
	f.seek(0)

def print_a_line(line_count, f):
	print(line_count, f.readline(), end='')

if __name__ == "__main__":
	current_file = open(input_file)
	print("First let us print the whole file:\n")

	print_all(current_file)

	print("\nNow let us rewind, like a tape.")

	rewind(current_file)

	print("Let\'s print three lines:\n")

	for current_line in range(1, 4):
		print_a_line(current_line, current_file)