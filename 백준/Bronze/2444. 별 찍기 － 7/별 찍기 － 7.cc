#include <iostream>
using namespace std;

int main()
{
    int num;
    
    cin >> num;
    
    int num2 = (2 * num) - 1;

    for ( int i = 0; i < num ; i++ )
    {
        for ( int j = 0; j < (num2 / 2) - i; j++ )
        {
            cout << " ";
        }
        for ( int k = 0; k <= i * 2; k++ )
        {
            cout << "*";
        }
        cout << endl;
    }

    num2 = (2 * --num) - 1;

    for ( int i = 0; i < num ; i++ )
    {
        for( int j = 0; j <= i; j++ )
        {
            cout << " ";
        }
        for( int j = num2 - (i*2); j > 0; j-- )
        {
            cout << "*";
        }

        cout << endl;
    }
}
