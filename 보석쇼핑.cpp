#include <string>
#include <vector>
using namespace std;

int ID = 0;
class Name{
public:
    Name(): child(), cnt(0), id(0){}
    bool Chk(string name){
        Name* curr = this;
        for(char ch: name){
            if(curr->child[ch-'A'] == nullptr) return true;
            curr = curr->child[ch-'A'];
        }
        return false;
    }
    
    void Insert(string name){
        Name * curr = this;
        
        for(char ch : name){
            curr->id = ID;
            curr->cnt++;
            if(curr->child[ch-'A'] == nullptr)
                curr->child[ch-'A'] = new Name();
            curr = curr->child[ch-'A'];
        }
        curr->cnt++;
        curr->id = ID++;
    }
    
    int Search(string name){
        Name * curr = this;
        for(char ch : name){
            if(curr->cnt == 1) return curr->id;
            curr = curr->child[ch-'A'];
        }
        return curr->id;
    }
    
private:
    int cnt;
    int id;
    Name* child[26];
};
Name nameList;
int visited[100005];
vector<int> solution(vector<string> gems) {
    
    vector<int> answer;
    int sz = gems.size();
    int total = 0;
    
    // 연결리스트로 정리
    for(string g :gems){
        if(nameList.Chk(g)) {
            nameList.Insert(g);
            total++;
        }
    }
    
    int ss = sz, ee = 1;
    int t = total, range = sz;
    bool flag = false;
    
    // 개수 찾기    
    for(int i = 0; i < sz; i++){
        int id = nameList.Search(gems[i]);
        if(visited[id] == 0) t--;
        visited[id] = i+1;

        if(!flag && t == 0){
            flag = true;
            for(int j = 0; j < total; j++){
                ss = ss < visited[j] ? ss : visited[j];
                ee = ee > visited[j] ? ee : visited[j];
            }
            range = ee-ss+1;
            if(range == total) break; 
        }
        else if(flag){
            int s = sz, e = 1;
            for(int j = 0; j < total; j++){
                s = s < visited[j] ? s : visited[j];
                e = e > visited[j] ? e : visited[j];
            }
            if(e-s+1 < range){
                range = e-s+1;
                ss = s, ee = e;
            }
            if(e-s+1 == total) break;  
        } 
    }

    answer.push_back(ss);
    answer.push_back(ee);
    return answer;
}
