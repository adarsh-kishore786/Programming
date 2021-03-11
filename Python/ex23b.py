import sys

sys.setrecursionlimit(10**6)

def write_line(file):
	if not file:
		return
	print((file.readline()).decode())
	write_line(file)

if __name__ == "__main__":
	script, address = sys.argv

	f = open(address, 'rb')
	write_line(f)
	f.close()