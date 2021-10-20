#include "trees.h"
#include <iostream>

TreeNode* buildTree() {
    TreeNode* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(7);

    TreeNode* tmp = root->left;
    tmp->left = newNode(1);
    tmp->right = newNode(6);

    return root;
}

TreeNode* buildTree2() {
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);

    TreeNode* tmp = root->left;
    tmp->left = newNode(11);
    tmp = tmp->left;
    tmp->left = newNode(7);
    tmp->right = newNode(2);

    tmp = root->right;
    tmp->left = newNode(13);
    tmp->right = newNode(4);
    tmp->right->right = newNode(2);

    return root;
}

TreeNode* buildTree3() {
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);

    TreeNode* tmp = root->left;
    tmp->left = newNode(1);
    tmp->right = newNode(3);

    return root;
}

bool sameTree(TreeNode* root1, TreeNode* root2) {
    if (!root1 && root2) return false;
    if (root1 && !root2) return false;
    if (!root1 && !root2) return true;
    if (root1->val != root2->val) return false;

    return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right);
}

bool isBST(TreeNode* root) {
    if (!root) return true;
    static TreeNode* prev = nullptr;

    if (!isBST(root->left)) return false;
    if (prev && prev->val > root->val) return false;
    prev = root;

    return isBST(root->right);
}

int main() {
    TreeNode* root1 = buildTree();
    TreeNode* root2 = buildTree2();

    std::cout << "root1 == root2: " << (sameTree(root1, root2) ? "Yes" : "No") << "\n";

    TreeNode* root3 = buildTree3();
    std::cout << "root3 is BST? " << (isBST(root3) ? "Yes" : "No") << "\n";
    std::cout << "root1 is BST? " << (isBST(root1) ? "Yes" : "No") << "\n";
}
