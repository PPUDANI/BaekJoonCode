#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) 
{
    int answer = 0;
    int Count = 0;
    vector<int> Stack;
    Stack.push_back(0);
    for(int i = 0; i < ingredient.size(); ++i)
    {
        if(ingredient[i] == 1 && Stack.back() == 123)
        {
            ++Count;
            Stack.pop_back();
        }
        else if(ingredient[i] == 2 && Stack.back() == 1)
        {
            Stack.back() = 12;
        }
        else if(ingredient[i] == 3 && Stack.back() == 12)
        {
            Stack.back() = 123;
        }
        else 
        {
            Stack.push_back(ingredient[i]);
        }
    }
    
    return Count;
}