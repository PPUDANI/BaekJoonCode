
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int N, Money;
    cin >> N >> Money;
    
    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    
    int Cnt = 0;
    for (int i = N - 1 ; i >= 0; --i)
    {
        while (Money >= vec[i])
        {
            Money -= vec[i];
            ++Cnt;
        }
        
        if(Money == 0)
        {
            break;
        }
    }
    
    cout << Cnt;
}
