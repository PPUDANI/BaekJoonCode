
#include <iostream>
#include <vector>
using namespace std;

#define MAX_NODE 101

vector<vector<int>> Graph(101, vector<int>());
bool visited[MAX_NODE] = {false,};
int Count = 0;
void dfs(int Node)
{
    visited[Node] = true;
    
    for(int i = 0; i < Graph[Node].size(); i++)
    {
        if (!visited[Graph[Node][i]])
        {
            dfs(Graph[Node][i]);
            Count++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    
    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        Graph[first].push_back(second);
        Graph[second].push_back(first);
    }
    
    dfs(1);
    
    cout << Count;
}