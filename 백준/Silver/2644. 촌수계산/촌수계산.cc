
#include <iostream>
#include <vector>
using namespace std;

vector<int> Graph[101];
bool visited[101] = {false, };

int n ,m;
int Start, End;

int res = -1;

bool dfs(int CurNode, int depth)
{
    visited[CurNode] = true;
    if(CurNode == End)
    {
        res = depth;
        return true;
    }
    
    for (int i : Graph[CurNode])
    {
        if (!visited[i])
        {
            if (dfs(i, depth + 1))
            {
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
    
    cin >> n >> Start >> End >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int first, second;
        cin >> first >> second;
        Graph[first].push_back(second);
        Graph[second].push_back(first);
    }
    
    dfs(Start, 0);
    cout << res;
}