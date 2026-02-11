#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int Graph[502][502] = {{0, }};
bool visited[502][502] = {{false, }, };
int MaxSize = 0;
int PaintCount = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int bfs(int StartY, int StartX)
{
    stack<pair<int, int>> q;
    q.push({StartY, StartX});
    visited[StartY][StartX] = true;
    int Count = 0;
    while (!q.empty())
    {
        int CurY = q.top().first;
        int CurX = q.top().second;
        q.pop();
        ++Count;
        
        for (int i = 0; i < 4; ++i)
        {
            int NextY = CurY + dy[i];
            int NextX = CurX + dx[i];

            if (!visited[NextY][NextX] && Graph[NextY][NextX] == 1)
            {
                visited[NextY][NextX] = true;
                q.push({NextY, NextX});
            }
        }
    }
    
    return Count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int y, x;
    cin >> y >> x;
    
    for(int i = 1; i <= y; ++i)
    {
        for(int j = 1; j <= x; ++j)
        {
            cin >> Graph[i][j];
        }
    }
    
    
    for(int i = 1; i <= y; ++i)
    {
        for(int j = 1; j <= x; ++j)
        {
            if (!visited[i][j] && Graph[i][j] == 1)
            {
                int Size = bfs(i, j);
                MaxSize = max(MaxSize, Size);
                ++PaintCount;
            }
        }
    }
    cout << PaintCount << '\n' << MaxSize;
}