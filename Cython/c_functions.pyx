from libc.stdlib cimport atoi
from libc.math cimport sin

def parse(s):
  return parse_charptr_to_py_int(s)

def f(x):
  return _f(x)
  
cdef parse_charptr_to_py_int(char* s):
  assert s is not NULL
  return atoi(s)

cdef double _f(double x):
  return sin(x * x)
