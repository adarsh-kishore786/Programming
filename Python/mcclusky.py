def gen_min_term(x, num_var):
	b = bin(x)[2:]
	length = len(b)
	fill = (num_var) - length if (num_var > length) else 0;

	return "0" * fill + b

def num_ones(term):
	count = 0
	for c in term:
		if c == '1':
			count += 1
	return count

def form_group(num_var, min_terms):
	groups = []

	for i in range(num_var + 1):
		temp = []
		for m in min_terms:
			if num_ones(m) == i:
				temp.append(m)
		groups.append(temp)
	return groups

def one_bit_diff(bnum1, bnum2, num_var):
	num1 = int(bnum1, 2)
	num2 = int(bnum2, 2)
	diff = abs(num1 - num2)

	for i in range(num_var):
		if diff == 2**i:
			return i
	return -1

def pairing(groups, num_var):
	group2 = []
	for (i, g) in enumerate(groups):
		if i == len(groups) - 1:
			break
		g1 = groups[i + 1]

		temp = []
		for bnum1 in g:
			for bnum2 in g1:
				p = one_bit_diff(bnum1, bnum2, num_var)
				if p != -1:
					in1 = "" if p == 0 else bnum1[: p - 1]
					in2 = "" if p == 0 else bnum2[: p - 1]
					out1 = 

					bnum1 = temp1 + 'x' + bnum1[p:]
					bnum2 = temp2 + 'x' + bnum2[p:]
					temp.append((bnum1, bnum2))
			group2.append(temp)
	return group2


if __name__ == "__main__":
	num_var = int(input("Enter number of variables: "))

	print("Enter the minterms like [m0, m1, m2, ...]: ")
	terms = eval(input())

	min_terms = [gen_min_term(i, num_var) for i in range(2**num_var) 
				if i in terms]
	print(min_terms)

	groups = form_group(num_var, min_terms)
	print(groups)
	print(pairing(groups, num_var))