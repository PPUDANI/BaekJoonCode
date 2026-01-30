#include <iostream>
using namespace std;
int arr[20000001] = {0, };
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int Num;
        cin >> Num;
        arr[Num + 10000000]++;
    }
    
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int Num;
        cin >> Num;
        if(arr[Num + 10000000] == 1)
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
}