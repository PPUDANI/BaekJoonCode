#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    for ( int i = 0; i < num; i++ )
    {
        for ( int k = num - i; k > 1; k-- )
        {
            cout << " ";
        }
        for ( int j = 0; j <= i; j++ )
        {
            cout << "*";
        }
        cout << endl;
    }
}