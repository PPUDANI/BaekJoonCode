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
    cin >> str;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<int> vec = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        res += vec[alpha.find(str[i])];
    }
    cout << res;
}