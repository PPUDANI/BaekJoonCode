#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    
    int n;
    int res = 0;
    cin >> n >> str;
    while(n--)
    {
        res += str[n] - '0';
    }
    
    cout << res;
}