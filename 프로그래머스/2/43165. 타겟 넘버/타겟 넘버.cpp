#include <string>
#include <vector>

using namespace std;

int count = 0;
int Gtarget;

void bfs(const vector<int>& numbers, int Index, int sum)
{
    if(numbers.size() <= Index)
    {
        if(sum == Gtarget)
        {
            ++count;
        }
        return;
    }
    
    bfs(numbers, Index + 1, sum + numbers[Index]);
    bfs(numbers, Index + 1, sum - numbers[Index]);
}

int solution(vector<int> numbers, int target) 
{
    Gtarget = target;
    bfs(numbers, 0, 0);
    
    return count;
}
