#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <vector>
#include <iostream>
#include <map>

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
  friend std::ostream& operator<<(std::ostream&, const DisjointSet);
};

#endif
