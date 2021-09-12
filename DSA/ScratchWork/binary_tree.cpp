#include <iostream>
#include <algorithm>
#include <exception>

using dType = int;

template <typename T>
struct Node
{
    T val;
    Node<T>* rightNode;
    Node<T>* leftNode;
};

template <typename T>
int getHeight(Node<T>* root)
{
    if (!root)
        return 0;

    return 1 + std::max(getHeight(root->leftNode), getHeight(root->rightNode));
}

template <class T>
class BinaryTree
{
private:
    Node<T>* root = nullptr;

public:
    BinaryTree() {}

    void insert(T val)
    {
        Node<T>* newNode { new Node<T>[sizeof(Node<T>)] };
        newNode->val = val;
        newNode->rightNode = nullptr;
        newNode->leftNode = nullptr;

        if (!root)
        {
            root = newNode;
            return;
        }

        Node<T>* currNode = root;
        while (currNode)
        {
            T oldVal = currNode->val;
            if (val > oldVal)
            {
                if (currNode->rightNode)
                {
                    currNode = currNode->rightNode;
                    continue;
                }
                currNode->rightNode = newNode;
                break;
            }
            else if (val < oldVal)
            {
                if (currNode->leftNode)
                {
                    currNode = currNode->leftNode;
                    continue;
                }
                currNode->leftNode = newNode;
                break;
            }
            else
                throw std::runtime_error("Duplicate value.");
        }
    }

    int height()
    {
        return getHeight(root);
    }

    friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& bt)
    {
        return os;
    }
};

template <typename T>
void insert_element(BinaryTree<T>& root)
{
    std::cout << "Enter value to insert: ";
    T value {};
    std::cin >> value;

    root.insert(value);
    std::cout << "Successfully inserted " << value << "!\n\n";
}

int main()
{
    BinaryTree<dType> root{};

    do
    {
        try
        {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Insert an element\n";
            std::cout << "2. Get height of tree\n";
            std::cout << "3. Quit\n";
            std::cout << "Enter your choice.\n";

            int ch {};
            std::cin >> ch;

            switch (ch)
            {
                case 1: insert_element(root);
                        break;
                case 2: std::cout << "Height is " << root.height() << ".\n\n";
                        break;
                case 3: return 0;
                default: std::cout << "Invalid option. Try again.\n\n";
            }
        }
        catch (std::runtime_error e)
        {
            std::cerr << e.what() << "\n\n";
        }
    }
    while(true);


    return 0;
}
