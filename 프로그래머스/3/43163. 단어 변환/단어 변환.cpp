#include <string>
#include <vector>

using namespace std;


bool visited[51] = {false, };
int MinCount = 51;
string TargetWord;

void DFS(const string& word, const vector<string>& words, int count)
{
    if(word == TargetWord)
    {
        MinCount = min(count, MinCount);
        return;
    }
    
    for(int i = 0; i < words.size(); ++i)
    {
        if(visited[i] == true)
        {
            continue;
        }
        
        int DifCnt = 0;
        for(int j = 0; j < word.length(); ++j)
        {
            if(word[j] != words[i][j]) DifCnt++;
        }

        if(DifCnt == 1)
        {
            visited[i] = true;
            DFS(words[i], words, count + 1);
            visited[i] = false;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) 
{
    TargetWord = target;
    DFS(begin, words, 0);
    
    if(MinCount == 51)
    {
        return 0;
    }
    
    return MinCount;
}