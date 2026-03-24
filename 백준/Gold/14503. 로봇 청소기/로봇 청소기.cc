#include <iostream>
#include <vector>
using namespace std;

// 0: North
// 1: East 
// 2: South
// 3: West
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> Map;

bool CrossCheck(int _Y, int _X, int CheckNum)
{
    for (int i = 0; i < 4; ++i)
    {
        if (Map[_Y + dy[i]][_X + dx[i]] == CheckNum)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    Map.assign(N, vector<int>(M, 0));
    
    int StartX, StartY;
    int StartDir;
    cin >> StartY >> StartX >> StartDir;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> Map[i][j];
        }
    }
    

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
        else if (!CrossCheck(CurY, CurX, 0))
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
        else if (CrossCheck(CurY, CurX, 0))
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