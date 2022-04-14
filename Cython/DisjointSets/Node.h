#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
  int val;
  Node* parent;
  int rank;

public:
  Node();
  Node(int);
  ~Node();

  int getValue();
  Node* getParent();
  int getRank();

  void setValue(int);
  void setParent(Node*);
  void setRank(int);

  friend std::ostream& operator<<(std::ostream& out, const Node*);
};

#endif
