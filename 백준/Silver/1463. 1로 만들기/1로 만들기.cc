#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    queue<pair<int, int>> q;
    q.push({N, 0});
    
    while (!q.empty())
    {
        auto CurData = q.front();
        q.pop();
        
        if (CurData.first == 1)
        {
            cout << CurData.second;
            return 0;
        }
        
        CurData.second += 1;
        
        if (CurData.first % 3 == 0)
        {
            q.push({CurData.first / 3, CurData.second});
        }
        
        if (CurData.first % 2 == 0)
        {
            q.push({CurData.first / 2, CurData.second});
        }
        
        q.push({CurData.first - 1, CurData.second});
    }
}