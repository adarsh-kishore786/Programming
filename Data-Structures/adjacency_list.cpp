/* 
    Let us create a graph for the tree 
                    1
                |           |
                2           5       
            |       |   
            3       4  

    but this time using the concept of 
    adjacency list.    
*/

#include <iostream>
#include <vector>
using namespace std;

void printGraph(vector<vector<int>>& graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Adjacent nodes of " << i+1 << ": ";
        for (int e : graph[i])
            cout << e << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> graph;
    graph.push_back({2, 5});
    graph.push_back({1, 3, 4});
    graph.push_back({2});
    graph.push_back({2});
    graph.push_back({1});

    printGraph(graph);
    cout << endl;

    return 0;
}