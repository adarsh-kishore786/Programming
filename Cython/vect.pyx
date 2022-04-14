# distutils: language = c++

from __future__ import print_function
from vector cimport MyVector

cdef class PyVector:
  cdef MyVector mv

  def __cinit__(self):
    self.mv = MyVector()

  def addElement(self, int x):
    self.mv.addElement(x)

  def getSize(self):
    return self.mv.getSize()

  def getElement(self, int index):
    return self.mv.getElement(index)

  def printVector(self):
    for i in range(self.mv.getSize()):
      print(self.mv.getElement(i), end=' ')
    print()
