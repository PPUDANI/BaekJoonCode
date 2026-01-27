#include <vector>

using namespace std;

vector<vector<int>>* GDungeons;
bool visited[8] = {false, };
int Count = 0;
int dfs(int stemina, int CurCount)
{
    for(int i = 0; i < GDungeons->size(); ++i)
    {
        if(visited[i] == false && (*GDungeons)[i][0] <= stemina)
        {
            visited[i] = true;
            Count = max(Count, dfs(stemina - (*GDungeons)[i][1], CurCount + 1));
            visited[i] = false;
        }
    }
    return CurCount;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    GDungeons = &dungeons;
    dfs(k, 0);
    return Count;
}
