"""
matrix.py

Author: Adarsh
"""

from vector import Vector

class Matrix:
	"""
	This class defines a matrix as a 
	table of numbers and also defines
	the operations of matrix algebra.
	"""

	def __init__(self, numbers=0, nrows=0, ncols=0):
		"""
		Initializes a matrix in two possible ways, using
		a 2D list of numbers or else a scalar value with
		the number of rows and columns specified.

		>>> A = Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
		>>> A.entries
		[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
		>>> A.nrows
		3
		>>> A.ncols
		3
		>>> A.rows
		[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
		>>> A.cols
		[[1, 4, 7], [2, 5, 8], [3, 6, 9]]

		>>> B = Matrix(numbers=0, nrows=3, ncols=3)
		>>> B.entries
		[[0, 0, 0], [0, 0, 0], [0, 0, 0]]
		>>> B.nrows
		3
		>>> B.ncols
		3

		"""
		if isinstance(numbers, list):
			self.entries = numbers
			self.nrows = len(numbers)
			self.ncols = len(numbers[0])
		elif isinstance(numbers, int) or isinstance(numbers, float):
			self.nrows = nrows
			self.ncols = ncols
			self.entries = []
			for i in range(self.nrows):
				temp = []
				for j in range(self.ncols):
					temp.append(numbers)
				self.entries.append(temp)

		self.rows = numbers
		self.cols = []
		for j in range(self.ncols):
			temp = []
			for i in range(self.nrows):
				temp.append(self.entries[i][j])
			self.cols.append(temp)

	@property	
	def dim(self):
		"""
		Returns the dimensions of the matrix
		(rows x columns).

		>>> M = Matrix([[-1, -2, 7], [4, 5, 0]])
		>>> print(M.dim)
		2 x 3
		"""
		return "{0} x {1}".format(self.nrows, self.ncols)

	def __neg__(self):
		"""
		Negates a matrix by negating each
		of the entries of the matrix.

		>>> M = Matrix([[1, 2], [-3, 4]])
		>>> print(-M)
		Dimensions: 2 x 2
		Matrix:
		 -1  -2 
		  3  -4 
		<BLANKLINE>
		"""
		for i in range(self.nrows):
			for j in range(self.ncols):
				self.entries[i][j] = -self.entries[i][j]
		return self

	def __add__(self, other):
		"""
		Adds two matrices of compatible dimensions
		according to laws of matrix algebra.

		>>> A = Matrix([[1, 2], [0, -9]])
		>>> B = Matrix([[8, 3.14], [3, 6]])
		>>> print(A + B)
		Dimensions: 2 x 2
		Matrix:
		    9  5.14 
		    3    -3 
		<BLANKLINE>

		>>> C = Matrix([[1, 2, 3], [3, 6, 7]])
		>>> A + C
		Traceback (most recent call last):
		...
		ValueError: The dimensions do not match: 2 x 2 with 2 x 3
		"""
		if (self.dim != other.dim):
			Matrix.__dim_mismatch(self, other)
			return
		result = []
		for i in range(self.nrows):
			temp = []
			for j in range(self.ncols):
				temp.append(self.entries[i][j] + other.entries[i][j])
			result.append(temp)
		return Matrix(result)

	def __iadd__(self, other):
		"""
		Shorthand addition in place.
		"""
		return Matrix.__add__(self, other)

	def __mul__(self, other):
		"""
		Multiplies two matrices of compatible 
		dimensions or a matrix and a scalar according 
		to the laws of matrix algebra.

		>>> A = Matrix([[4, 5], [6, 7], [1, 2]])
		>>> B = A.T
		>>> print(A * B)
		Dimensions: 3 x 3
		Matrix:
		 41  59  14 
		 59  85  20 
		 14  20   5 
		<BLANKLINE>

		>>> print(A * 2)
		Dimensions: 3 x 2
		Matrix:
		  8  10 
		 12  14 
		  2   4 
		<BLANKLINE>
		"""
		result = []
		if isinstance(other, int) or isinstance(other, float):
			for i in range(self.nrows):
				temp = []
				for j in range(self.ncols):
					temp.append(self.entries[i][j] * other)
				result.append(temp)
			return Matrix(result)

		if (self.ncols != other.nrows):
			Matrix.__dim_mismatch(self, other)
			return

		for i in range(self.nrows):
			temp = []
			for j in range(other.ncols):
				sum = 0
				for k in range(self.ncols):
					sum += self.entries[i][k] * other.entries[k][j]
				temp.append(sum)
			result.append(temp)
		return Matrix(result)

	@property
	def basis(self):
		"""
		Returns the basis vectors which 
		constitute the columns of the 
		matrix.

		>>> A = Matrix([[9, 5], [-1, 0]])
		>>> v = A.basis
		>>> for vector in v:
		... 	print(vector)
		<BLANKLINE>
		Dimension of vector: 2
		The vector:
		 9
		-1
		<BLANKLINE>
		<BLANKLINE>
		Dimension of vector: 2
		The vector:
		 5
		 0
		<BLANKLINE>
		"""
		return [Vector(col) for col in self.cols]
	
	@property
	def T(self):
		"""
		Returns the transpose of a matrix.

		>>> A = Matrix([[1, 2], [-6, 7], [0, 8]])
		>>> print(A)
		Dimensions: 3 x 2
		Matrix:
		  1   2 
		 -6   7 
		  0   8 
		<BLANKLINE>

		>>> print(A.T)
		Dimensions: 2 x 3
		Matrix:
		  1  -6   0 
		  2   7   8 
		<BLANKLINE>
		"""
		result = [] 
		for j in range(self.ncols):
			temp = []
			for i in range(self.nrows):
				temp.append(self.entries[i][j])
			result.append(temp)
		return Matrix(result)

	def __dim_mismatch(self, other):
		"""
		Raises a ValueError if the dimensions 
		of the two matrices do not match.
		"""
		raise ValueError("The dimensions do not match: {0} with {1}".
			format(self.dim, other.dim))

	@property	
	def issquare(self):
		if self.nrows == self.ncols:
			return True
		raise ValueError("The matrix is not square")
	
	def multiply_row(self, row, scalar):
		"""
		Retruns a matrix with the 
		corresponding row multiplied by
		the corressponding scalar.

		>>> A = Matrix([[1.3, 1.5], [9, 0.5]])
		>>> print(A.multiply_row(1, 2))
		Dimensions: 2 x 2
		Matrix:
		 2.6  3.0 
		   9  0.5 
		<BLANKLINE>
		"""
		result = self.entries
		for j in range(self.ncols):
			result[row - 1][j] *= scalar
		return Matrix(result)

	def add_row(self, receiver, adder, scalar=1):
		"""
		Adds a multiple of one row to another.

		>>> M = Identity(3)
		>>> M = M.add_row(2, 3, 3)
		>>> M = M.add_row(1, 2)
		>>> print(M)
		Dimensions: 3 x 3
		Matrix:
		 1  1  3 
		 0  1  3 
		 0  0  1 
		<BLANKLINE>
		"""
		result = self.entries
		for j in range(self.ncols):
			result[receiver - 1][j] += result[adder - 1][j] * scalar
		return Matrix(result)

	def exchange_row(self, row1, row2):
		"""
		Exchanges two rows of a matrix.
		
		>>> M = Matrix([[1, 2, 3], [9.8, 5.2, 12.34], [0, 2, 1]])
		>>> M = M.exchange_row(1, 2)
		>>> print(M)
		Dimensions: 3 x 3
		Matrix:
		   9.8    5.2  12.34 
		     1      2      3 
		     0      2      1 
		<BLANKLINE>
		"""
		result = self.entries
		result[row1 - 1], result[row2 - 1] = \
			 result[row2 - 1], result[row1 - 1]
		return Matrix(result)

	def diagonalize(self, row=1):
		result = self
		if row > self.nrows:
			return result;

		for i in range(row+1, self.nrows + 1):
			if (result.entries[row-1][row-1] == 0):
				continue
			result = result.add_row(i, row, \
				-result.entries[i-1][row-1]/result.entries[row-1][row-1])
		return result.diagonalize(row+1);

	@property
	def determinant(self):
		"""
		Calculates the determinant of a 
		square matrix.

		>>> A = Identity(3)
		>>> A.determinant
		1.0

		>>> B = Matrix([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
		>>> B.determinant
		0

		>>> C = Matrix([[2.5, 3.6, 1], [0.1, 0.4, 45.67], [12, 34.5, 19.5]])
		>>> C.determinant
		-1954.9635

		>>> D = Matrix([[1, 2, 3], [4, 5, 6]])
		>>> D.determinant
		Traceback (most recent call last):
		...
		ValueError: The matrix is not square
		"""
		self.issquare

		d = self.diagonalize()
		result = 1.0
		for i in range(self.nrows):
			if d.entries[i][i] == 0:
				result = 0
				break;
			result *= d.entries[i][i]

		return round(result, 4)

	def __repr__(self):
		"""
		Returns an eval-able representation of the
		matrix. 

		>>> A = Matrix([[1, 2], [6, -1]])
		>>> A
		Matrix([[1, 2], [6, -1]])
		"""
		result = "Matrix("
		result += str(self.entries) + ")"
		return result

	def __str__(self):
		"""
		Returns the string representation of 
		a matrix in a form that user can 
		understand.

		>>> M = Matrix([[6, 2], [4, 1]])
		>>> print(M)
		Dimensions: 2 x 2
		Matrix:
		 6  2 
		 4  1 
		<BLANKLINE>

		>>> A = Matrix([[16, 20], [-34, 0]])
		>>> print(A)
		Dimensions: 2 x 2
		Matrix:
		  16   20 
		 -34    0 
		<BLANKLINE>		
		"""
		largest = ""
		for row in self.entries:
			for entry in row:
				if len(str(round(entry, 2))) > len(largest):
					largest = str(round(entry, 2))

		length = len(largest) + 1

		result = ""
		result += "Dimensions: {0} x {1}\n".format(self.nrows, self.ncols)
		result += "Matrix:\n"
		for i in range(self.nrows):
			for j in range(self.ncols):
				result += ("{0:>" + str(length) + "} ").format(round(self.entries[i][j], 2))
			result += '\n'
		return result

class Identity(Matrix):
	"""
	Special class for creating an 
	identity matrix. Rest all workings 
	the same.

	>>> I = Identity(2)
	>>> basis = I.basis
	>>> for v in basis:
	... 	print(v)
	<BLANKLINE>
	Dimension of vector: 2
	The vector:
	 1
	 0
	<BLANKLINE>
	<BLANKLINE>
	Dimension of vector: 2
	The vector:
	 0
	 1
	<BLANKLINE>
	"""

	def __init__(self, size):
		"""
		Creates an identity matrix of 
		given size. We can then further
		modify it into an elementary matrix.

		>>> I = Identity(3)
		>>> print(I)
		Dimensions: 3 x 3
		Matrix:
		 1  0  0 
		 0  1  0 
		 0  0  1 
		<BLANKLINE>

		>>> I.entries[0][1] = 2
		>>> print(I)
		Dimensions: 3 x 3
		Matrix:
		 1  2  0 
		 0  1  0 
		 0  0  1 
		<BLANKLINE>
		"""
		result = []
		for i in range(size):
			temp = []
			for j in range(size):
				temp.append(1 if i == j else 0)
			result.append(temp)
		super().__init__(result)

if __name__ == "__main__":
	import doctest
	doctest.testmod()
