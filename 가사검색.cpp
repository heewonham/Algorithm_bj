#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Song{
public :
    Song() : child(), cnt(0) {}
    void Insert(string str){
        
        Song* curr = this;
        
        for(char ch : str){
            curr->cnt++;
            if(curr->child[ch-'a'] == nullptr)
                curr->child[ch-'a'] = new Song();
            
            curr = curr->child[ch-'a'];
        }
        // 마지막 노드 증가
        curr->cnt++;
    }
    
    int Search(string str){
        Song* cur = this;
  
        for(char ch : str){
            if(ch == '?') return cur->cnt;
            cur = cur->child[ch-'a'];
            if(cur == nullptr) return 0;
                
        }
        return 0;
    }

private :
    int cnt;
    Song* child[26];
};

Song Array[10005];
Song ArrayRev[10005];

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(string str : words){
        int sz = str.size()-1;
        Array[sz].Insert(str);
        
        reverse(str.begin(), str.end());
        ArrayRev[sz].Insert(str);
    }
    
    // 검색
    for(string str: queries){
        int sz = str.size()-1;
        if(str[0] == '?'){ // 역방향 찾기
            reverse(str.begin(), str.end());
            answer.push_back(ArrayRev[sz].Search(str));
        }
        else{
            answer.push_back(Array[sz].Search(str));
        }
    }
    return answer;
}
