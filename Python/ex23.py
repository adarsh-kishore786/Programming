import sys

def main(language_file, encoding, errors, file):
	line = language_file.readline()

	if line:
		print_line(line, encoding, errors, file)
		return main(language_file, encoding, errors, file)

def print_line(line, encoding, errors, file):
	next_lang = line.strip()
	raw_bytes = next_lang.encode(encoding, errors=errors)
	cooked_string = raw_bytes.decode(encoding, errors=errors)

	print(raw_bytes, "<===>", cooked_string)
	file.write(f"{raw_bytes}\n")

if __name__ == "__main__":
	script, input_encoding, error = sys.argv
	languages = open("languages.txt", encoding="utf-8")
	file = open("ex23_output.txt", 'w')
	main(languages, input_encoding, error, file)
	file.close()	

	print(b"\xc2\xb0".decode())