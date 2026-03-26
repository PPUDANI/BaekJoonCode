#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin >> n;
    set<int> us;
    for (int i = 0; i < n; ++i)
    {
        int Num;
        cin >> Num;
        us.insert(Num);
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int Num;
        cin >> Num;
        if (us.find(Num) == us.end())
        {
            cout << "0\n";
        }
        else
        {
            cout << "1\n";
        }
    }
    
}