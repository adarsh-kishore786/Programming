"""
logistic_sequence.py

This program finds the terms of a
discrete logistic seqnence.

Author: Adarsh
"""

def next(k, p, n, count):
	if count == n:
		return
	p_1 = k * p * (1 - p)
	print("{count}. p = {p}".format(**locals()))
	next(k, p_1, n, count + 1);


if __name__ == "__main__":
	while True:
		try:
			n = int(input("Enter the number of terms in the series: "))
			k = float(input("Enter the proportinality (1 < k < 3): "))
			p_0 = float(input("Enter the original population as a fraction: "));
		except KeyError:
			print("You entered an invalid value.")
			print("Rebooting...\n")
			continue

		if p_0 > 1 or p_0 < 0:
			print("This is an invalid population. Rebooting...\n")
			continue
		break

	next(k, p_0, n, 1)