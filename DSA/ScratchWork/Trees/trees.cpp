#include "trees.h"
#include <algorithm>
#include <iostream>

TreeNode* newNode(int value) {
    TreeNode* node = new TreeNode;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

TreeNode* insert(TreeNode* root, int data) {
    if (!root) return newNode(data);

    if (data <= root->val) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

void printTreeInOrder(TreeNode* root) {
    if (!root) return;

    printTreeInOrder(root->left);
    std::cout << root->val << " ";
    printTreeInOrder(root->right);
}

void printTreePreOrder(TreeNode* root) {
    if (!root) return;

    std::cout << root->val << " ";
    printTreeInOrder(root->left);
    printTreeInOrder(root->right);
}

void printTreePostOrder(TreeNode* root) {
    if (!root) return;

    printTreeInOrder(root->left);
    printTreeInOrder(root->right);
    std::cout << root->val << " ";
}

int size(TreeNode* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// int minValue(TreeNode* root) {
//     if (!root) return 0;
//     if (!root->left) return root->val;
//     return minValue(root->left);
// }

// int main() {
//     TreeNode* root = newNode(5);
//     root = insert(root, 10);
//     root = insert(root, 3);
//     root = insert(root, -5);
//
//     // std::cout << root->right->val << std::endl;
//     std::cout << "In Order: ";
//     printTreeInOrder(root);
//     std::cout << "\nPre Order: ";
//     printTreePreOrder(root);
//     std::cout << "\nPost Order: ";
//     printTreePostOrder(root);
//     std::cout << "\n";
//
//     std::cout << "Size: " << size(root) << "\n";
//     std::cout << "Max Depth: " << maxDepth(root) << "\n";
//     std::cout << "Min Value: " << minValue(root) << "\n";
// }
