"""
Here we are trying to construct 
a convergent sub-sequence from
sin(n), as guaranteed by the 
Bolzano-Weirstrass theorem.
"""

import math

def pi_multiple(p):
	return int(math.pi * 10**p)

def calc_sin(r):
	for i in range(1, r):
		sin = math.sin(pi_multiple(i))
		print(f"sin([10**{i} * pi]) = {sin}")

if __name__ == "__main__":
	calc_sin(10**3)

	print("This sub-sequence does not converge.")