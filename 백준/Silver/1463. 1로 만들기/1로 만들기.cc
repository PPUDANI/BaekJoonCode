#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int Num;
    int Cnt;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    int Cnt = 0;
    queue<Node> Q;
    Q.push({N, 0});
    
    while (true)
    {
        Node CurNode = Q.front();
        Q.pop();
        
        if (CurNode.Num == 1)
        {
            Cnt = CurNode.Cnt;
            break;
        }
        
        CurNode.Cnt++;
        
        if (CurNode.Num % 3 == 0)
        {
            Q.push({CurNode.Num / 3, CurNode.Cnt});
        }
        
        if (CurNode.Num % 2 == 0)
        {
            Q.push({CurNode.Num / 2, CurNode.Cnt});
        }
        
        Q.push({CurNode.Num - 1, CurNode.Cnt});
    }
    
    cout << Cnt;
}