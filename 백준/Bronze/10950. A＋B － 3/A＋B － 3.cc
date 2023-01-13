#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, a, b;
    vector <int> res;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        res.push_back(a + b);
    }

    for (auto i : res)
    {
        cout << i << endl;
    }
}