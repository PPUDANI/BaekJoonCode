#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    unordered_map<string, int> Functions;
    Functions.insert({"add", 0});
    Functions.insert({"remove", 1});
    Functions.insert({"check", 2});
    Functions.insert({"toggle", 3});
    Functions.insert({"all", 4});
    Functions.insert({"empty", 5});
    
    
    int N;
    cin >> N;
    
    string str; 
    int S = 0;
    int x;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        
        switch (Functions[str])
        {
        case 4: // all
            S = (1 << 21) - 1; // 1~20 비트를 모두 1로 (1000...00 - 1)
            break;
        case 5: // empty
            S = 0; // 모든 비트 0으로
            break;
        case 0: // add
            cin >> x;
            S |= (1 << x); // x번째 비트를 1로 설정
            break;
        case 1: // remove
            cin >> x;
            S &= ~(1 << x); // x번째 비트를 0으로 설정
            break;
        case 2: // check
            cin >> x;
            if (S & (1 << x))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
            break;
        case 3: // toggle
            cin >> x;
            S ^= (1 << x); // x번째 비트 반전 (1이면 0, 0이면 1)
            break;
        }
    }
}
