#include "trees.h"
#include <iostream>
#include <vector>

void printPath(std::vector<int> paths, int path_num) {
    std::cout << "Path " << path_num << ": ";
    for (int val : paths)
        std::cout << val << " ";
    std::cout << "\n";
}

void printPaths(TreeNode* root) {
    static std::vector<int> path {};
    static int path_num = 1;
    if (!root) return;
    if (!root->left && !root->right) {
        path.push_back(root->val);
        printPath(path, path_num++);
        path.pop_back();
        return;
    }
    path.push_back(root->val);
    printPaths(root->left);
    printPaths(root->right);
    path.pop_back();
}

TreeNode* mirror(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    root->left = mirror(root->left);
    root->right = mirror(root->right);
    return root;
}

TreeNode* buildTree() {
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);

    TreeNode* tmp = root->left;
    tmp->left = newNode(1);
    tmp->right = newNode(3);

    return root;
}

TreeNode* buildTree2() {
    TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    return root;
}

TreeNode* doubleTree(TreeNode* root) {
    if (!root) return nullptr;

    TreeNode* tmp = root->left;
    root->left = newNode(root->val);
    root->left->left = tmp;

    root->left->left = doubleTree(root->left->left);
    root->right = doubleTree(root->right);

    return root;
}

int main() {
    TreeNode* root = buildTree();

    std::cout << "In Order: ";
    printTreeInOrder(root);
    std::cout << "\nPre Order: ";
    printTreePreOrder(root);
    std::cout << "\nPost Order: ";
    printTreePostOrder(root);
    std::cout << "\n";

    printPaths(root);

    root = mirror(root);
    std::cout << "\nIn Order: ";
    printTreeInOrder(root);
    std::cout << "\nPre Order: ";
    printTreePreOrder(root);
    std::cout << "\nPost Order: ";
    printTreePostOrder(root);
    std::cout << "\n";

    printPaths(root);

    root = buildTree2();

    std::cout << "\nIn Order: ";
    printTreeInOrder(root);
    std::cout << "\nPre Order: ";
    printTreePreOrder(root);
    std::cout << "\nPost Order: ";
    printTreePostOrder(root);
    std::cout << "\n";

    printPaths(root);

    root = doubleTree(root);
    std::cout << "\nIn Order: ";
    printTreeInOrder(root);
    std::cout << "\nPre Order: ";
    printTreePreOrder(root);
    std::cout << "\nPost Order: ";
    printTreePostOrder(root);
    std::cout << "\n";

    printPaths(root);
}
