
#include <iostream>
#include <vector>
using namespace std;

vector<int> Graph[101];
bool visited[101] = {false, };
int Start, End;

bool dfs(int CurNode, int depth, int& Count)
{
    visited[CurNode] = true;
    if(CurNode == End)
    {
        return true;
    }
    
    for (int i : Graph[CurNode])
    {
        if (!visited[i])
        {
            if (dfs(i, depth + 1, Count))
            {
                Count++;
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    

    cin >> Start >> End;
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        Graph[first].push_back(second);
        Graph[second].push_back(first);
    }
    int Count = 0;
    if (dfs(Start, 0, Count))
    {
        cout << Count;
    }
    else
    {
        cout << -1;
    }
}