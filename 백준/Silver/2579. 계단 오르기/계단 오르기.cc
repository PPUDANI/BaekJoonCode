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
    DP[2] = Stairs[1] + Stairs[2];
    for (int i = 3; i <= N; ++i)
    {
        DP[i] = max(DP[i - 2] + Stairs[i], DP[i - 3] + Stairs[i - 1] + Stairs[i]);
    }
    
    cout << DP[N];
}