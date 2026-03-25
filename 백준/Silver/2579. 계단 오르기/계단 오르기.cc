#include<iostream>
using namespace std;

int Stairs[301] = {0,};
int DP[301]= {0,};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> Stairs[i];
    }
    
    DP[1] = Stairs[1];
    DP[2] = DP[1] + Stairs[2];
    
    for (int i = 0; i <= N - 2; ++i)
    {
        int NewScore = DP[i] + Stairs[i + 2];
        DP[i + 2] = max(DP[i + 2] , NewScore);
        DP[i + 3] = max(DP[i + 3], NewScore + Stairs[i + 3]);
    }
    
    cout << DP[N];
}