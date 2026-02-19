#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Graph(101);

int dfs(int CurNode, bool* IsVisit, int DeleteNode)
{
    IsVisit[CurNode] = true;
    int size = 1;
    for (int i : Graph[CurNode])
    {
        if (!IsVisit[i] && i != DeleteNode)
        {
            size += dfs(i, IsVisit, DeleteNode);
        }
    }
    return size;
}

int CountSubTree(int StartNode, int DeleteNode)
{
    bool IsVisit[101] = {false, };
    return dfs(StartNode, IsVisit, DeleteNode);
}

int solution(int n, vector<vector<int>> wires) 
{
    Graph.clear();
    for(vector<int> wire : wires)
    {
        Graph[wire[0]].push_back(wire[1]);
        Graph[wire[1]].push_back(wire[0]);
    }
    
    int answer = 100;
    for(vector<int> wire : wires)
    {
        int NumOfLeft = CountSubTree(wire[0], wire[1]);
        int NumOfRight = CountSubTree(wire[1], wire[0]);
        answer = min(answer, abs(NumOfLeft - NumOfRight));
    }
    
    return answer;
}
