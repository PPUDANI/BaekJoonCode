#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> Graph(N + 1, vector<int>()); 
    for (int i = 0; i < M; ++i)
    {
        int left, right;
        cin >> left >> right;
        Graph[left].push_back(right);
        Graph[right].push_back(left);
    }
    
    vector<int> Visit(N + 1, 0);
    
    stack<int, vector<int>> st;
    st.push(1);
    Visit[1] = 1;
    int Count = 0;
    while (!st.empty())
    {
        int CurNode = st.top();
        st.pop();
        
        for (int NextNode : Graph[CurNode])
        {
            if (Visit[NextNode] == 0)
            {
                Visit[NextNode] = 1;
                ++Count;
                st.push(NextNode);
            }
        }
    }

    cout << Count;
}