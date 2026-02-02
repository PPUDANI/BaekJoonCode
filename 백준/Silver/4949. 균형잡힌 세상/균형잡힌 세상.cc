#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

bool ParenthesesCheck()
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if  (str[i] == '(' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (st.size() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (st.size() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    
    return st.empty();
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(getline(cin, str))
    {
        if (str == ".")
        {
            break;
        }
        
        if (ParenthesesCheck())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
}
