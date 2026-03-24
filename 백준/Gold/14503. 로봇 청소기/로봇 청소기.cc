#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    
    int StartX, StartY;
    int StartDir;
    cin >> StartY >> StartX >> StartDir;
    
    vector<vector<int>> Map(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Map[i][j];
        }
    }
    
    // 0: North
    // 1: East 
    // 2: South
    // 3: West
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    int CurX = StartX;
    int CurY = StartY;
    int CurDir = StartDir;
    int Count = 0;
    
    while (true)
    {
        if (Map[CurY][CurX] == 0)
        {
            Map[CurY][CurX] = 2;
            Count++;
        }
        else if (
            Map[CurY+1][CurX] != 0 &&
            Map[CurY-1][CurX] != 0 &&
            Map[CurY][CurX+1] != 0 &&
            Map[CurY][CurX-1] != 0)
        {
            // Turn Back 
            int BackDir = (CurDir + 2) % 4;
            CurY += dy[BackDir];
            CurX += dx[BackDir];
            if (Map[CurY][CurX] == 1)
            {
                break;
            }
        }
        else if (Map[CurY+1][CurX] == 0 ||
            Map[CurY-1][CurX] == 0 ||
            Map[CurY][CurX+1] == 0 ||
            Map[CurY][CurX-1] == 0)
        {
            // Turn Left 
            CurDir = (CurDir + 3) % 4;
            
            if ( Map[CurY + dy[CurDir]][CurX + dx[CurDir]] == 0)
            {
                CurY += dy[CurDir];
                CurX += dx[CurDir];
            }
        }
    }
    cout << Count;
}