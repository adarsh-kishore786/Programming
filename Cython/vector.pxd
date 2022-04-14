from libcpp.vector cimport vector

cdef extern from "vector.cpp":
  cdef cppclass MyVector:
    vector v
    int size
    MyVector() except +
    void addElement(int)
    int getSize()
    int getElement(int) except +
    
