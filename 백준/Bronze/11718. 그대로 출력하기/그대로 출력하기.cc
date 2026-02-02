#include <iostream>
#include <string>
using namespace std;

string str;
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(getline(cin, str))
    {
        cout << str << endl;
    }
}