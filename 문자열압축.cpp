#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int sz = s.length();
    int answer = sz;
    
    // 1 ~ n/2 개수만큼 나눌 수 있다.
    for(int i = 1; i < (sz/2)+1; i++){
        string prev, l = "";
        int cnt = 1;
        
        prev = s.substr(0,i);
        for(int j = i; j < sz; j += i){
            string next = s.substr(j,i);
            if(prev == next) { cnt++;}
            else{
                if((i == 1 && cnt == 1) || cnt == 1){
                    l.append(prev);
                }
                else{
                    l.append(to_string(cnt)+prev);
                    
                }
                prev = next;
                cnt = 1;
            }
        }
        if(cnt > 1) l.append(to_string(cnt)+prev);
        else l.append(prev);
        answer = answer > l.length()? l.length() : answer;
    }
    
    return answer;
}
