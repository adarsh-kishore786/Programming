def next(a1, a2, count, n):
	if count == 0:
		return 
	print("{0}. {1}".format((n - count + 1), a1))
	a1 = (a1 + a2) / 2

	next(a2, a1, count - 1, n)

if __name__ == "__main__":
	while True:
		try:
			a1 = int(input("Enter the first term: "))
			a2 = int(input("Enter the second term: "))
			n = int(input("Enter the number of terms: "))
		except KeyError:
			print("Invalid input. Rebooting...\n")
			continue
		except EOFError:
			break

		print("\n")
		next(a1, a2, n, n)

		c = input("Run again? (Y/N): ")
		if c == 'y' or c == 'Y':
			continue
		else:
			break
