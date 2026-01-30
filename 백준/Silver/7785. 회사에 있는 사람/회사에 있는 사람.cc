#include <iostream>
#include <map>
using namespace std;


int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<string, bool> logs;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        string Name, Check;
        cin >> Name >> Check;
        if (Check == "enter")
        {
            logs[Name] = true;
        }
        else if (Check == "leave")
        {
            logs[Name] = false;
        }
    }
    
    for(map<string, bool>::reverse_iterator iter = logs.rbegin(); iter != logs.rend(); iter++)
    {
        if ((*iter).second == true)
        {
            cout << (*iter).first << "\n";
        }
    }
}