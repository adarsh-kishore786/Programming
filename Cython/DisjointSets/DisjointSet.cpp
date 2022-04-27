#include <iostream>
#include <set>
#include <map>
#include "DisjointSet.h"

Node::Node(int value) {
  this->val = value;
  this->parent = this;
  this->rank = 0;
}

Node::Node(): Node::Node(0) {}

Node::~Node() {
  delete this->parent;
}

int Node::getValue() {
  return this->val;
}

Node* Node::getParent() {
  return this->parent->val;
}

int Node::getRank() {
  return this->rank;
}

void Node::setValue(int val) {
  this->val = val;
}

void Node::setRank(int rank) {
  this->rank = rank;
}

void Node::setParent(Node* parent) {
  this->parent = parent;
}

std::ostream& operator<<(std::ostream& out, const Node* node) {
  out << "Value : " << node->val << std::endl;
  out << "Parent: " << node->parent << std::endl;
  out << "Rank  : " << node->rank << std::endl << std::endl;
  return out;
}


DisjointSet::DisjointSet() {
  this->nodes = {};
}

DisjointSet::~DisjointSet() {
}

void DisjointSet::makeSet(int index) {
  this->nodes.push_back(new Node(index));

}

Node* DisjointSet::findSet(int index) {
  Node* x = this->nodes[index];
  while (x->getParent() != x)
    x = x->getParent();
  return x;
}

void DisjointSet::unionSet(int i, int j) {
  Node** x = &this->nodes[i];
  Node** y = &this->nodes[j];


  Node* t_x = &this->nodes[this->findSet(i)];
  Node* t_y = &this->nodes[this->findSet(j)];

  Node** r_x = &t_x;
  Node** r_y = &t_y;

  if (r_x != r_y) {
    if ((*r_y)->getRank() < (*r_x)->getRank()) {
      (*r_x)->setParent(*r_y);
    } else if ((*r_y)->getRank() > (*r_x)->getRank()){
      (*r_y)->setParent(*r_x);
    } else {
      (*r_x)->setParent(*r_y);
      (*r_y)->setRank((*r_y)->getRank() + 1);
    }
  }
}

std::vector<Node*> DisjointSet::getNodes() {
  return this->nodes;
}

int DisjointSet::numComponents() {
  std::set<Node*> roots {};

  for (int i = 0; i < this->nodes.size(); i++) {
    Node* r = this->findSet(i);
    roots.insert(r);
  }
  return roots.size();
}

std::map<int, std::vector<Node*>> DisjointSet::components() {
  int n = this->numComponents();
  std::map<int, std::vector<Node*>> components {};
  for (int i = 0; i < this->nodes.size(); i++) {
    int r = this->findSet(i)->getValue();
    components[r].push_back(this->nodes[i]);
  }
  return components;
}

std::ostream& operator<<(std::ostream& out, DisjointSet ds) {
  auto components = ds.components();
  int i = 1;
  for (const auto& pair : components) {
    out << "Component " << i++ << ": \n";
    auto nodes_ = pair.second;
    for (auto& e : nodes_)
      out << e;
  }
  return out;
}

int main() {
  DisjointSet ds;

  ds.makeSet(0);
  ds.makeSet(1);
  ds.makeSet(2);
  ds.makeSet(3);
  ds.unionSet(0, 1);
  ds.unionSet(2, 3);
  ds.unionSet(1, 2);

  std::vector<Node*> nodes = ds.getNodes();
  for (int i = 0; i < nodes.size(); i++)
    std::cout << nodes[i];

  std::cout << "Number of connected components: " << ds.numComponents() << std::endl;
  std::cout << "\nThe components:" << std::endl;
  std::cout << ds << std::endl;
}
