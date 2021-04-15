"""
caesar_shift.py

Demonstates the caesar shifting encryption
algorithm.
"""
TOTAL_ALPHA = 26

def encrypt(sent, shift_val):
	newstr = ""
	for c in sent:
		if not c.isalpha():
			newstr += c
			continue
		n = 65 if ('A' <= c <= 'Z') else 97
		c = chr(((ord(c) - n + shift_val) % TOTAL_ALPHA) + n)
		newstr += c 
	return newstr

if __name__ == "__main__":
	s = input("Enter sentence to be encrypted: ")
	shift = int(input("Enter shift value: "))

	print(encrypt(s, shift))
