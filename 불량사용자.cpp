#include <string>
#include <vector>
#include <set>
using namespace std;

set<set<int>> poss;
set<int> tmp;
bool visited[11];
vector<int> l[9];

bool chk(string id, string banned){
    for(int i = 0; i < banned.size(); i++){
        if(banned[i] == '*') continue;
        if(id[i] != banned[i]) return false;
    }
    return true;
}
void dfs(int idx, int bansz){
    
    if(idx == bansz){
        poss.insert(tmp);
        return;
    } 
    
    for(int j : l[idx]){
        if(!visited[j]){
            visited[j] = true;
            tmp.insert(j);
            dfs(idx+1, bansz);
            tmp.erase(j);
            visited[j] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    // 불량아이디로 선정될 가능성이 있는 리스트 산출
    for(int i = 0; i < banned_id.size(); i++){
        int sz = banned_id[i].size();
        for(int j = 0; j < user_id.size(); j++){
            if(user_id[j].size() == sz){
                if(chk(user_id[j],banned_id[i])) l[i].push_back(j);
            }
        }
    }
    
    // 가능한 조합 확인
    dfs(0, banned_id.size());
    answer = poss.size();
    
    return answer;
}
