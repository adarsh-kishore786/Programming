#include <iostream>
#include <vector>

struct Heap {
    int val;
    Heap* left;
    Heap* right;
};

Heap* newNode(int val) {
    Heap* node = new Heap;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

Heap* heapify(Heap* head, const std::vector<int>& v, int index) {
    if (index > v.size())
        return nullptr;
    head = newNode(v[index - 1]);
    head->left = heapify(head->left, v, 2 * index);
    head->right = heapify(head->right, v, 2 * index + 1);

    return head;
}

Heap* heapify(const std::vector<int>& v) {
    return heapify(nullptr, v, 1);
}

void printInOrder(Heap* node) {
    if (!node)
        return;
    printInOrder(node->left);
    std::cout << node->val << " ";
    printInOrder(node->right);
}

void printPreOrder(Heap* node) {
    if (!node)
        return;
    std::cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Heap* head = heapify(v);
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\n";
}
