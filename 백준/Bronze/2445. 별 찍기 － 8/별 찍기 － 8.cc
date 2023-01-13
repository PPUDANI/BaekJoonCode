#include <iostream>
using namespace std;

int main()
{
    int num;
    
    cin >> num;
    
    int num2 = (2 * num) - 1;
    for ( int i = 0; i < num ; i++ )
    {
        for( int j = 0; j <= i; j++ )
        {
            cout << "*";
        }
        for( int j = num2 - (i * 2); j > 1; j-- )
        {
            cout << " ";
        }
        for( int j = 0; j <= i; j++ )
        {
            cout << "*";
        }
        cout << endl;
    }

    num2 = (2 * --num) - 1;

    for ( int i = 0; i < num ; i++ )
    {
        for ( int j = 0; j <= (num2 / 2) - i; j++ )
        {
            cout << "*";
        }
        for ( int k = num2 - (i * 2); k <= num2 + 1; k++ )
        {
            cout << " ";
        }
        for ( int j = 0; j <= (num2 / 2) - i; j++ )
        {
            cout << "*";
        }
        cout << endl;
    }
}