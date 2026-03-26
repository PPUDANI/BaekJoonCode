#include <iostream>
#include <queue>
using namespace std;
#define INF 100000000
int main()
{
    int N;
    cin >> N;
    
    vector<int> DP(N+1, INF);
    
    DP[1] = 0;
    for (int i = 1; i < N; ++i)
    {
        int CurCount = DP[i] + 1;
        int Times3 = i * 3;
        int Times2 = i * 2;
        int Plus1 = i + 1;
        
        if (Times3 <= N)
        {
            DP[Times3] = min(DP[Times3], CurCount);
        }
        
        if (Times2 <= N)
        {
            DP[Times2] = min(DP[Times2], CurCount);
        }
        
        if (Plus1 <= N)
        {
            DP[Plus1] = min(DP[Plus1], CurCount);
        }
    }
    
    cout << DP[N];
}