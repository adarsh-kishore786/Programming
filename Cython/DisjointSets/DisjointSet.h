#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>
#include <iostream>
#include <map>
#include "Node.h"

class DisjointSet {
private:
  std::vector<Node*> nodes;

public:
  DisjointSet();
  ~DisjointSet();

  void makeSet(int);
  Node* findSet(int);
  void unionSet(int, int);

  std::vector<Node*> getNodes();

  int numComponents();
  std::map<int, std::vector<Node*>> components();
};

#endif
