#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int NumOfStair;
    cin >> NumOfStair;
    
    int Stairs[305] = {0, };
    int DP[305] = {0, };
    for (int i = 1; i <= NumOfStair; i++)
    {
        cin >> Stairs[i];
    }
    
    DP[1] = Stairs[1];
    DP[2] = DP[1] + Stairs[2];
    
    for (int i = 0; i <= NumOfStair - 2; i++)
    {
        int firstScore = DP[i] + Stairs[i + 2];
        DP[i + 2] = max(DP[i + 2], firstScore);
        DP[i + 3] = max(DP[i + 3], firstScore + Stairs[i + 3]);
    }
    
    cout << DP[NumOfStair];
}