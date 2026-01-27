#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    int NumOfDungeons = dungeons.size();
    vector<bool> Visited_Base(NumOfDungeons, false);
    stack<pair<vector<int>, vector<bool>>, vector<pair<vector<int>, vector<bool>>>> DFS;
    
    for(int i = 0; i < NumOfDungeons; ++i)
    {
        if(dungeons[i][0] <= k)
        {
            Visited_Base[i] = true;
            vector<int> Score = {k - dungeons[i][1], 1};
            DFS.push({Score, Visited_Base});
            Visited_Base[i] = false;
        }
    }
    
    int Count = 0;
    while(!DFS.empty())
    {
        vector<int> CurScore = DFS.top().first;
        vector<bool> CurVisited = DFS.top().second;
        DFS.pop();
        
        Count = max(Count, CurScore[1]);
        for(int i = 0; i < NumOfDungeons; ++i)
        {
            if(CurVisited[i] == false && dungeons[i][0] <= CurScore[0])
            {
                CurVisited[i] = true;
                DFS.push({{CurScore[0] - dungeons[i][1], CurScore[1] + 1}, CurVisited} );
                CurVisited[i] = false;
                cout << CurScore[1] + 1 << endl;
            }
        }
    }
    
    return Count;
}
int main()
{
    cout << solution(80,	{{80,20},{50,40},{30,10}});
}