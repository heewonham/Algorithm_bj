#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<string, int> pii;
bool chk(string bef, string aft){
    
    int cnt = 0;
    vector<bool> is_same(10,false);
    for(int i = 0; i < bef.size(); i++){
        for(int j = 0; j < aft.size(); j++){
            if(!is_same[j] && bef[i] == aft[j]){
                cnt ++; is_same[j] = true;
                break;
            }
        }
    }

    if(cnt >= bef.size()-1) return true;
    else return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<pii,int>> q;
    vector<vector<bool>> visited;
    
    q.push(make_pair(pii(begin,0),0));
    vector<bool> v(words.size(),false);
    visited.push_back(v);
    while(!q.empty()){
        
        bool flag = false;
        string bef = q.front().first.first;
        int cnt = q.front().first.second;
        int idx = q.front().second;
        q.pop();
        
        if(bef == target) {answer = cnt; break;}
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[idx][i] && chk(bef,words[i])){
                if (!flag) {
                    flag = true;
                    visited[idx][i] = true;
                    q.push(make_pair(pii(words[i],cnt+1),idx));
                }
                else{
                    vector<bool> vv;
                    for(int j = 0; j < words.size(); j++){
                        vv.push_back(visited[idx][j]);
                    }
                    visited.push_back(vv);
                    visited[++idx][i] = true;
                    q.push(make_pair(pii(words[i],cnt+1),idx));
                }
                
            }
                
        }
    }
    
    return answer;
}
