#include <string>
#include <vector>

using namespace std;
int visited[1000000];
string ans_string = "a";

void dfs(vector<vector<string>> &tickets, string cur, string path, int depth) {
    if (depth == tickets.size()) {
        string p = path;
        if (path < ans_string) {
            ans_string = path;
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (cur == tickets[i][0] && !visited[i]) {
            visited[i] = 1;
            dfs(tickets, tickets[i][1], path + tickets[i][1], depth+1);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    dfs(tickets, "ICN", "ICN", 0);
    for (int i = 0; i < ans_string.size(); i+=3) {
        answer.push_back(ans_string.substr(i, 3));
    }
    return answer;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool visited[10000];

// ���� �˰���
void DFS(int *cnt, string from, vector<string> &ans, vector<vector<string>> &tickets){
    
    if(*cnt == tickets.size()+1) return; 
    
    for(int i = 0; i < tickets.size(); i++){
        if(!visited[i] && from == tickets[i][0]){
            // �ϳ� �ֱ�
            visited[i] = true; (*cnt)++;
            ans.push_back(tickets[i][1]);
            // ����
            DFS(cnt, tickets[i][1], ans, tickets);
            // ���� �� ã�Ҵٸ� ����
            if(*cnt == tickets.size()+1) return; 
            // �ٸ� ���� ã�Ƴ���
            visited[i] = false;
            ans.pop_back(); (*cnt)--;
        }    
    }
    
    return;
}
// ����
int compare(vector<string> a, vector<string> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}
vector<string> solution(vector<vector<string>> tickets) {
    
    vector<string> answer;
    int t_s = tickets.size();
    int cnt = 1;
    
    // ����
    sort(tickets.begin(), tickets.end(),compare);
    
    // �˰��� ����
    answer.push_back("ICN");
    DFS(&cnt, "ICN", answer, tickets);
    return answer;
}
