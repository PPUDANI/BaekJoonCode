#include <iostream>
#include <set>
using namespace std;


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<string> logs;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string Name, Check;
        cin >> Name >> Check;
        if (Check == "enter")
        {
            logs.insert(Name);
        }
        else if (Check == "leave")
        {
            logs.erase(Name);
        }
    }
    
    for(set<string>::reverse_iterator iter = logs.rbegin(); iter != logs.rend(); iter++)
    {
        cout << (*iter) << "\n";
    }
}