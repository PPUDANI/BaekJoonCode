#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int NumOfStair;
    cin >> NumOfStair;
    
    int Stairs[301] = {0, };
    int DP[301];
    for (int i = 1; i <= NumOfStair; i++)
    {
        cin >> Stairs[i];
    }
    
    DP[0] = 0;
    DP[1] = Stairs[1];
    DP[2] = DP[1] + Stairs[2];
    
    for(int i = 3; i <= NumOfStair; i++)
    {
        int Step1 = DP[i - 3] + Stairs[i - 1] + Stairs[i];
        int Step2 = DP[i - 2] + Stairs[i];
        DP[i] = max(Step1, Step2);
    }
    
    cout << DP[NumOfStair];
}