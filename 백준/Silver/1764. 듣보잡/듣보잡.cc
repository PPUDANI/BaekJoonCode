#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    unordered_set<string> us;
    set<string> res;
    int count = 0;
    for (int i = 0; i < N + M; ++i)
    {
        string str;
        cin >> str;
        if (us.find(str) == us.end())
        {
            us.insert(str);
        }
        else
        {
            ++count;
            res.insert(str);
        }
    }
    
    cout << count << "\n";
    for (const string& str : res)
    {
        cout << str << "\n";
    }
}