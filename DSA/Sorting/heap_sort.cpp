#include <iostream>
#include <vector>
#include <tuple>

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

Heap* max_heapify(Heap* head) {
    if (!head)
        return nullptr;

    head->left = max_heapify(head->left);
    head->right = max_heapify(head->right);

    if (head->left && head->right) {
        int maxVal = std::max(head->val, std::max(head->left->val, head->right->val));
        if (maxVal == head->left->val)
            std::tie(head->val, head->left->val) = std::make_pair(head->left->val, head->val);
        else if (maxVal == head->right->val)
            std::tie(head->val, head->right->val) = std::make_pair(head->right->val, head->val);
    }
    else if (head->left) {
        if (head->left->val > head->val)
            std::tie(head->val, head->left->val) = std::make_pair(head->left->val, head->val);
    }
    else if (head->right) {
        if (head->right->val > head->val)
            std::tie(head->val, head->right->val) = std::make_pair(head->right->val, head->val);
    }
    head->left = max_heapify(head->left);
    head->right = max_heapify(head->right);

    return head;
}

Heap* getLeaf(Heap* head) {
    if (head && !head->left && !head->right)
        return head;
    else if (head && !head->left)
        return getLeaf(head->right);
    else if (head && !head->right)
        return getLeaf(head->left);
    else if (head) {
        Heap* leaf1 = getLeaf(head->left);
        Heap* leaf2 = getLeaf(head->right);
        if (leaf1->val > leaf2->val)
            return leaf2;
        else
            return leaf1;
    }
    return nullptr; // Should never happen
}

bool deleteChild(Heap* head, Heap* node) {
    if (!head || head == node)
        return false;
    if (head->left == node) {
        head->left = nullptr;
        return true;
    }
    else if (head->right == node) {
        head->right = nullptr;
        return true;
    }
    else if (!deleteChild(head->left, node) && !deleteChild(head->right, node))
        return false;
    return false;
}

Heap* getMax(Heap* head, int& max) {
    if (!head)
        return nullptr;
    Heap* min = getLeaf(head);
    max = head->val;
    if (head == min)
        return nullptr;

    head->val = min->val;
    deleteChild(head, min);

    return max_heapify(head);
}

std::vector<int> heap_sort(const std::vector<int>& v) {
    Heap* head = max_heapify(heapify(v));
    int max = 0;
    std::vector<int> final {};

    while (head) {
        head = getMax(head, max);
        final.push_back(max);
    }
    std::reverse(final.begin(), final.end());
    return final;
}

void printVector(const std::vector<int>& v) {
    for (auto e : v)
        std::cout << e << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {1, 2, 3, 5, 321, 90, -1, 34, 42};
    Heap* head = heapify(v);
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\n";

    head = max_heapify(head);
    std::cout << "\nAfter doing max-heapify:\n";
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\n";

    int max = 0;
    head = getMax(head, max);

    std::cout << "\nAfter doing extract-max:\n";
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\nMax: " << max << "\n";

    head = getMax(head, max);
    std::cout << "\nAfter doing extract-max:\n";
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\nMax: " << max << "\n";

    head = getMax(head, max);
    std::cout << "\nAfter doing extract-max:\n";
    std::cout << "Inorder : ";
    printInOrder(head);
    std::cout << "\n";
    std::cout << "Preorder: ";
    printPreOrder(head);
    std::cout << "\nMax: " << max << "\n";

    v = heap_sort(v);
    std::cout << "Sorted: ";
    printVector(v);
}
