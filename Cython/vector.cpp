#include <iostream>
#include <vector>

class MyVector {
private:
  std::vector<int> v;
  size_t size;

public:
  MyVector() { v = {}; size = 0; }

  void addElement(int x) {
    v.push_back(x);
    size++;
  }

  size_t getSize() {
    return size;
  }

  int getElement(int i) {
    assert (i >= 0 and i < size);
    return v[i];
  }
};
