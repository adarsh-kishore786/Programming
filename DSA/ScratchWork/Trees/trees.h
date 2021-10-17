struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int value);
TreeNode* insert(TreeNode* root, int value);
void printTreeInOrder(TreeNode* root);
void printTreePreOrder(TreeNode* root);
void printTreePostOrder(TreeNode* root);

int size(TreeNode* root);
int maxDepth(TreeNode* root);
int minValue(TreeNode* root);
