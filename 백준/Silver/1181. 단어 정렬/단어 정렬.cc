#include<iostream>
#include<string>
#include<set>

using namespace std;

struct compare
{
    bool operator()(const string & str1, const string & str2) const
    {
        if (str1.length() < str2.length())
        {
            return true;
        }
        else if (str1.length() > str2.length())
        {
            return false;
        }
        else
        {
            int Length = str1.length();
            for (int i = 0; i < Length; i++)
            {
                if (str1[i] < str2[i])
                {
                    return true;
                }
                else if (str1[i] > str2[i])
                {
                    return false;
                }
            }
        }
        return false;
    }
};

int main()
{
    int N;
    cin >> N;
    set<string, compare> strs;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        strs.insert(str);
    }

    for (const string& str : strs)
    {
        cout << str << "\n";
    }
}
