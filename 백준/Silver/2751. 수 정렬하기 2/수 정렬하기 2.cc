
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; ++i)
    {
        int Num;
        cin >> Num;
        s.insert(Num);
    }
    
    for (int i : s)
    {
        cout << i << "\n";
    }
}
