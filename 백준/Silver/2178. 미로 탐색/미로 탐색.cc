#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define IS_VISIT 2;

struct Node
{
    int Y;
    int X;
    int Dist;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    
    cin >> N >> M;
    
    vector<vector<int>> Map(N + 2, vector<int>(M + 2, 0));
    for (int i = 1; i <= N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; ++j)
        {
            Map[i][j] = s[j - 1] - '0';
        }
    }
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    queue<Node> q;
    vector<vector<bool>> IsVisited(N + 2, vector<bool>(M + 2, false));
    IsVisited[1][1] = true;
    q.push({1, 1, 1});
    
    while (!q.empty())
    {
        Node CurNode = q.front();
        q.pop();
        
        if (CurNode.Y == N && CurNode.X == M)
        {
            cout << CurNode.Dist;
            return 0;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = CurNode.Y + dy[i];
            int NextX = CurNode.X + dx[i];
            if (Map[NextY][NextX] == 1 &&
                IsVisited[NextY][NextX] == false)
            {
                IsVisited[NextY][NextX] = true;
                q.push({NextY, NextX, CurNode.Dist + 1});
            }
        }
    }
}