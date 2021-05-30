/* 
    This program demonstrates the use of 
    Depth First Search (DFS) on the graph
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
#include <queue>
using namespace std;

struct Node
{
    int val;
    bool covered;
    queue<Node*> adj_list;
};

void dfs(queue<Node*> node)
{
    if (!node.size())
    {
        cout << "Nothing here now. Returning.\n";
        cout << endl;
        return;
    }

    if (!(node.front()->covered))
    {
        cout << node.front()->val << " ";
        node.front()->covered = true;
        cout << "Going into adjacency list of " << node.front()->val << endl;
        dfs((node.front()->adj_list));
    }

    node.pop();
    dfs(node);
}

queue<Node*> genGraph()
{
    queue<Node*> nodes;
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

    n1->adj_list.push(n2);
    n1->adj_list.push(n5);

    n2->adj_list.push(n1);
    n2->adj_list.push(n3);
    n2->adj_list.push(n4);

    n3->adj_list.push(n2);
    n4->adj_list.push(n2);
    n5->adj_list.push(n1);

    nodes.push(n1);
    nodes.push(n2);
    nodes.push(n3);
    nodes.push(n4);
    nodes.push(n5);

    return nodes;
}

int main()
{
    queue<Node*> nodes = genGraph();
    dfs(nodes);
}