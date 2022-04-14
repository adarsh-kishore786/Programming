#include "Node.h"
// #include <iostream>

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
  return this->parent;
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
  out << "Parent: " << node->parent->val << std::endl;
  out << "Rank  : " << node->rank << std::endl << std::endl;
  return out;
}

// int main() {
//   Node* nodes[5];
//   for (int i = 0; i < 5; i++) {
//     nodes[i] = new Node(i);
//     nodes[i]->setParent(nodes[0]);
//     std::cout << nodes[i] << std::endl;
//   }
// }
