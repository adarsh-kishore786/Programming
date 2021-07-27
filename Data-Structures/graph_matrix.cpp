/* 
    Let us create a graph for the tree 
                    1
                |           |
                2           5       
            |       |   
            3       4      
*/

#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>>& m)
{
    for (vector<int> row : m)
    {   
        for (int e : row)
            cout << e << " ";
        cout << endl;
    }
}

void printTree(vector<vector<int>>& m)
{
    for (int i = 0; i < m.size(); i++)
    {
        cout << "Nodes to which " << i+1 << " is connected: ";
        for (int j = 0; j < m[i].size(); j++)
            if (m[i][j])
                cout << j + 1 << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({0, 1, 0, 0, 1});
    matrix.push_back({1, 0, 1, 1, 0});
    matrix.push_back({0, 1, 0, 0, 0});
    matrix.push_back({0, 1, 0, 0, 0});
    matrix.push_back({1, 0, 0, 0, 0});

    printMatrix(matrix);
    cout << endl;
    printTree(matrix);    
}
