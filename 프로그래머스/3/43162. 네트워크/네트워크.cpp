#include <string>
#include <vector>

using namespace std;
vector<bool> IsVisit;

void dfs(const vector<vector<int>>& computers, int Index)
{
    IsVisit[Index] = true;
    
    for(int i = 0; i < computers[Index].size(); ++i)
    {
        if(Index == i || computers[Index][i] == 0 || IsVisit[i])
        {
            continue;
        }
        
        dfs(computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    IsVisit.assign(n, false);
    
    int Count = 0;
    for(int i = 0; i < n; ++i)
    {
        if(IsVisit[i])
        {
            continue;
        }
        
        dfs(computers, i);
        Count++;
    }
    
    return Count;
}