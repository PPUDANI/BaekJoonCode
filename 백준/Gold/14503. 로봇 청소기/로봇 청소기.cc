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
    
    int CurX = StartX;
    int CurY = StartY;
    int CurDir = StartDir;
    int count = 0;
    
    while (true)
    {
        if (Map[CurY][CurX] == 0)
        {
            Map[CurY][CurX] = 2;
            count++;
        }
        else if (
            Map[CurY+1][CurX] != 0 &&
            Map[CurY-1][CurX] != 0 &&
            Map[CurY][CurX+1] != 0 &&
            Map[CurY][CurX-1] != 0)
        {
            switch (CurDir)
            {
            case 0:
                CurY += 1;
                break;
            case 1:
                CurX -= 1;
                break;
            case 2:
                CurY -= 1;
                break;
            case 3:
                CurX += 1;
                break;
            }
            
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
            int DirX = 0;
            int DirY = 0;
            switch (CurDir)
            {
            case 0:
                DirX = -1;
                break;
            case 1:
                DirY = -1;
                break;
            case 2:
                DirX = +1;
                break;
            case 3:
                DirY = +1;
                break;
            }

            if ( Map[CurY + DirY][CurX + DirX] == 0)
            {
                CurY += DirY;
                CurX += DirX;
            }
            
            CurDir = (CurDir - 1);
            if (CurDir < 0)
            {
                CurDir = 3;
            }
        }
    }
    cout << count;
}