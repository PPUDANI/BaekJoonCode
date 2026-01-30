#include <iostream>
#include <unordered_set>

using namespace std;


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_set<string> uset;
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        uset.insert(str);
    }
    
    int count = 0;
    for(int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if(uset.find(str) != uset.end())
        {
            ++count;
        }
    }
    cout << count;
}