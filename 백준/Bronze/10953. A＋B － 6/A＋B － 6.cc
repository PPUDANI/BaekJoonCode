#include <iostream>
using namespace std;

int main()
{
    int a, b, T;
    char c;
    cin >> T;
    while ( T )
    {
        cin >> a >> c >> b;
        cout << a + b << endl;
        T--;
    }
}