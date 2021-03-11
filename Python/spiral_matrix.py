def get_spiral(matrix):
	result = ""
	length = len(matrix)
	row0 = row1 = ""
	col0 = col1 = ""

	for i in range(length):
		col0 += str(matrix[i][0]) + " "
		col1 += str(matrix[i][-1]) + " "

	for j in range(length):
		if j == 0 or j == length - 1:
			continue
		row0 += matrix[0][j] + " "
		row1 += matrix[-1][j] + " "

	result += row0 + col1 + row1 + col0
	result += 