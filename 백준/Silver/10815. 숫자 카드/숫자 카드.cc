#include <iostream>
#include <map>
using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    map<int, int> Cards;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int Num;
        cin >> Num;
        Cards[Num]++;
    }
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int Num;
        cin >> Num;
        if(Cards[Num])
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
}