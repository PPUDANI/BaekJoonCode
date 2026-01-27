#include <string>
#include <vector>

using namespace std;
const string* Target;
bool visited[51] = {false, };
int MinCount = 51;

bool dfs(const string& begin, const vector<string>& words, int count)
{
    if(begin == (*Target))
    {
        return true;
    }
    
    for(int i = 0; i < words.size(); ++i)
    {
        if (visited[i] == true)
        {
            continue;
        }
        
        int difcount = 0;
        for(int j = 0; j < begin.length(); ++j)
        {
            if(begin[j] != words[i][j])
            {
                ++difcount;
            }
        }
        
        if(difcount == 1)
        {
            visited[i] = true;
            if(dfs(words[i], words, count + 1))
            {
                MinCount = min(count+1, MinCount);
            }
            visited[i] = false;
        }
    }
    
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    Target = &target;
    dfs(begin, words, 0);
    return MinCount == 51 ? 0 : MinCount;
}