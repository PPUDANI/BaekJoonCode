#include <iostream>
using namespace std;

int main()
{
    int num;
    
    cin >> num;
    
    int num2 = (2 * num) - 1;

    for ( int i = 0; i < num ; i++ )
    {
        for( int j = 0; j < i; j++ )
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