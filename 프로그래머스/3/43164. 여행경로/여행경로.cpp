#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<bool> visited;

bool dfs(const string& airport, vector<vector<string>>& tickets, int count) {
    // 모든 항공권 사용 완료
    if(count == tickets.size()) {
        return true;
    }
    
    // 현재 공항에서 출발하는 항공권 찾기
    for(int i = 0; i < tickets.size(); i++) {
        if(!visited[i] && tickets[i][0] == airport) {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            
            // 재귀적으로 다음 공항 탐색
            if(dfs(tickets[i][1], tickets, count + 1)) {
                return true;  // 성공하면 즉시 종료
            }
            
            // 백트래킹 (이 경로로는 실패)
            answer.pop_back();
            visited[i] = false;
        }
    }
    
    return false;  // 이 경로로는 해답 없음
}

vector<string> solution(vector<vector<string>> tickets) {
    // 사전순 정렬
    sort(tickets.begin(), tickets.end());
    
    // 초기화
    visited.resize(tickets.size(), false);
    answer.push_back("ICN");  // 시작점
    
    // DFS 실행
    dfs("ICN", tickets, 0);
    
    return answer;
}