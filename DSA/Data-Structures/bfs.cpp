/* 
    This program demonstrates the use of 
    Breadth First Search (BFS) on the graph
                      1
                      |
                |-----------|
                2           5
                |
            ---------              
            |       |   
            3       4  
*/

#include <iostream>
#include <deque>
using namespace std;

struct Node
{
    int val;
    bool covered;
    deque<Node*> adj_list;
};

void bfs(deque<Node*> node)
{
    if (!node.size())
    {
        cout << "Nothing here now. Returning." << endl << endl;
        return;
    }
    if (!(node.front()->covered))
    {
        auto a_list = node.front()->adj_list;
        cout << "Adjacency list of " << node.front()->val << ": ";
        node.front()->covered = true;

        bool end = true;
        for (auto i = a_list.begin(); i != a_list.end(); i++)
        {
            cout << (*i)->val << " ";
            end = false;
        }
        cout << endl;
        if (!end)
            bfs(a_list);
    }

    node.pop_front();
    bfs(node);
}

deque<Node*> genGraph()
{
    deque<Node*> nodes;
    Node *n1, *n2, *n3, *n4, *n5;

    n1 = new Node;
    n1->val = 1;

    n2 = new Node;
    n2->val = 2;

    n3 = new Node;
    n3->val = 3;

    n4 = new Node;
    n4->val = 4;

    n5 = new Node;
    n5->val = 5;

    n1->adj_list.push_back(n2);
    n1->adj_list.push_back(n5);

    n2->adj_list.push_back(n1);
    n2->adj_list.push_back(n3);
    n2->adj_list.push_back(n4);

    n3->adj_list.push_back(n2);
    n4->adj_list.push_back(n2);
    n5->adj_list.push_back(n1);

    nodes.push_back(n1);
    nodes.push_back(n2);
    nodes.push_back(n3);
    nodes.push_back(n4);
    nodes.push_back(n5);

    return nodes;
}

int main()
{
    deque<Node*> nodes = genGraph();
    bfs(nodes);
}