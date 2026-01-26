#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

vector<vector<int>> Global_Dungeons;
vector<bool> Global_Visited;
int res = 0;

int dfs(int stemina, int count)
{
    if(stemina)
    for(int i = 0; i < Global_Dungeons.size(); ++i)
    {
        if(Global_Visited[i] == false &&
           Global_Dungeons[i][0] <= stemina && 
           Global_Dungeons[i][1] <= stemina)
        {
            Global_Visited[i] = true;
            res = max(res, dfs(stemina - Global_Dungeons[i][1], count + 1));
            Global_Visited[i] = false;
        }
    }
    
    return count;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    Global_Dungeons = dungeons;
    vector<bool> visited(dungeons.size(), false);
    Global_Visited = visited;

    dfs(k, 0);
    return res;
}

int main()
{
    int a = solution(80, {{80,20}, {50, 40}, {30, 10}});
    
    cout << a << endl;
}