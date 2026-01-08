#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    unordered_map<string, int> Functions;
    set<int> Numbers;
    set<int> AlllNumber = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    set<int> Empty;
    Functions.insert({"add", 0});
    Functions.insert({"remove", 1});
    Functions.insert({"check", 2});
    Functions.insert({"toggle", 3});
    Functions.insert({"all", 4});
    Functions.insert({"empty", 5});
    
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        string str; 
        int data;
        cin >> str;
        
        switch (Functions[str])
        {
        case 4: // all
            Numbers = AlllNumber;
            break;
        case 5: // empty
            Numbers = Empty;
            break;
        case 0: // add
            cin >> data;
            Numbers.insert(data);
            break;
        case 1: // remove
            cin >> data;
            Numbers.erase(data);
            break;
        case 2: // check
            cin >> data;
            cout << (Numbers.find(data) != Numbers.end()) << "\n";
            break;
        case 3: // toggle
            cin >> data;
            if (Numbers.find(data) != Numbers.end())
            {
                Numbers.erase(data);
            }
            else
            {
                Numbers.insert(data);
            }
            break;
        }
    }
}