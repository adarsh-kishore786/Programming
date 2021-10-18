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

bool hasPathSum(TreeNode* root, int sum) {
    static int s = 0;
    if (!root) return false;
    if (!root->left && !root->right) {
        s += root->val;
        if (s == sum) return true;
        s -= root->val;
        return false;
    }
    s += root->val;
    if (hasPathSum(root->left, sum) || hasPathSum(root->right, sum)) return true;
    s -= root->val;
    return false;
}

TreeNode* buildTree() {
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
    tmp->right->right = newNode(1);

    return root;
}

int minValue(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    if (!root->left && root->right) return std::min(root->val, minValue(root->right));
    if (root->left && !root->right) return std::min(root->val, minValue(root->left));

    return std::min(root->val, std::min(minValue(root->left), minValue(root->right)));
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

    std::cout << "Size: " << size(root) << "\n";
    std::cout << "Max Depth: " << maxDepth(root) << "\n";
    std::cout << "Min Value: " << minValue(root) << "\n";

    printPaths(root);
    int sum = 18;
    std::cout << "Does a path sum to " << sum << "? " << (hasPathSum(root, sum) ? "Yes" : "No") << "\n";
}
