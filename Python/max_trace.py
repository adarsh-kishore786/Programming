def input_matrix(N):
	A = []
	for i in range(N):
		temp = []
		for j in range(N):
			temp.append()
		A.append(temp)

	return A

def print_matrix(A):
	N = len(A)

	for i in range(N):
		for j in range(N):
			print(A[i][j], end=' ')
		print()

if __name__ == "__main__":
	T = int(input()) # Number of test cases

	while (T):
		N = int(input()) # Order of matrix
		A = input_matrix(N)

		print_matrix(A)

		T -= 1