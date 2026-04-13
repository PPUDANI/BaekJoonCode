#include <string>
#include <vector>

using namespace std;

bool IsVisit[200] = {false,};
void dfs(int CurNode, vector<vector<int>>& Graph)
{
    if(IsVisit[CurNode])
    {
        return;
    }
    else
    {
        IsVisit[CurNode] = true;
        for(int NextNode : Graph[CurNode])
        {
             dfs(NextNode, Graph);
        }
    }
}


int solution(int n, vector<vector<int>> computers) 
{
    vector<vector<int>> Graph(n, vector<int>());
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(computers[i][j] == 1)
            {
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
    
    int count = 0;
            
    for(int i = 0; i < n; ++i)
    {
        if(IsVisit[i] == false)
        {
            dfs(i, Graph);
            ++count;
        }

    }
    
    
    return count;
}