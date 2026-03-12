#include <string>
#include <vector>

#define PUDDLE 0

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) 
{

    vector<vector<int>> Grid(n, vector<int>(m, -1));
    
    for(int i = 0; i < puddles.size(); ++i)
    {
        Grid[puddles[i][1] - 1][puddles[i][0] - 1] = PUDDLE;
    }
    
    int InitNum = 1;
    for(int i = 0; i < n; ++i)
    {
        if(Grid[i][0] == PUDDLE)
        {
            InitNum = 0;
        }
        Grid[i][0] = InitNum;
    }
    
    InitNum = 1;
    for(int i = 0; i < m; ++i)
    {
        if(Grid[0][i] == PUDDLE)
        {
            InitNum = 0;
        }
        Grid[0][i] = InitNum;
    }
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            if(Grid[i][j] != PUDDLE)
            {
                Grid[i][j] = (Grid[i - 1][j] + Grid[i][j - 1]) % 1000000007;
            }
        }
    }
    
    return Grid[n-1][m-1];
}