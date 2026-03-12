#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) 
{
    int Height = triangle.size();
    
    vector<vector<int>> NewTri(triangle);
    
    for(int i = 0; i < Height - 1; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            NewTri[i+1][j] = max(NewTri[i+1][j], triangle[i+1][j] + NewTri[i][j]);
            NewTri[i+1][j+1] = max(NewTri[i+1][j+1] , triangle[i+1][j+1] + NewTri[i][j]);
        }
        cout << endl;
    }
    
    int answer = 0;
    for(int i = 0; i < Height; ++i)
    {
        answer = max(answer, NewTri[Height-1][i]);
    }
    
    return answer;
}