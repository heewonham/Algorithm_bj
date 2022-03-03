#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

typedef pair<string, string> pii;
vector<string> parsing(string str){
    vector<string> l;
    istringstream ss(str);
    string buf;
    
    while(getline(ss, buf, ' ')){
        l.push_back(buf);
    }
    
    return l;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> name;
    vector<pii> chatting;
    for(string s : record){
        vector<string> l = parsing(s);
        if(l.size() == 2){ // Leave
            chatting.push_back(pii(l[1],"님이 나갔습니다."));
        }
        else{ // Enter, Change
            if(l[0].compare("Enter") == 0){
                chatting.push_back(pii(l[1],"님이 들어왔습니다."));
            }
            else if(l[0].compare("Change") == 0){
                
            }
            name[l[1]] = l[2];
        }
    }
    
    for(pii ch : chatting){
        answer.push_back(name[ch.first]+ch.second);
    }
    return answer;
}
