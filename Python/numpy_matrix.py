import numpy as np

p = np.array([[1, 2, 9], [3, 4, 7], [1, 2, 3]])
q = np.array([[4, 5, 8], [6, 7, 1], [8, 9, 10]])

print("Matrix p:")
print(p, "\n")
print("Matrix q:")
print(q, "\n")

# find the dot product (both for vectors and matrices)
result = np.dot(p, q)
print("p.q =")
print(result, "\n")

# find cross-product
result = np.cross(p, q)
print("p x q =")
print(result, "\n")

# find eigenvalues
l = np.linalg.eigvals(p)
print("Eigenvalues of p:", l, "\n")

# find determinant
d = np.linalg.det(q)
print("Determinant of q:", d)

# find inverse of a non-singular matrix
r = np.linalg.inv(p)
print("Inverse of p:")
print(r, "\n")

# flatten a matrix
print("p flattened row major:", p.flatten())
print("p flattened column major:", p.flatten(order='F'))