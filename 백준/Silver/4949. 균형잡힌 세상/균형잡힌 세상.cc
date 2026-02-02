#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

bool ParenthesesCheck()
{
    stack<char> st;
    for (char c : str)
    {
        if  (c == '(' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')')
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
        else if (c == ']')
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
