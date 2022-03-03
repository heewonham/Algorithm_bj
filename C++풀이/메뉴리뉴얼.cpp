#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
unordered_map<string,int> mp[11];
int mx[11];
void dfs(string ord, int idx, string str){
    
    int sz = str.size();
    if(idx == ord.size()){
        if(sz > 1){
            mp[sz][str]++;
            if(mx[sz] < mp[sz][str]) mx[sz] = mp[sz][str];
        }
        return;
    }
    dfs(ord,idx+1,str+ord[idx]);
    dfs(ord,idx+1,str);
}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;

    for(string ord :orders){
        sort(ord.begin(), ord.end());
        dfs(ord, 0, "");
    }
	 
    for(int len : course){
        int val = mx[len];
        for(auto m : mp[len]){
            if(val >= 2 && m.second == val)
                answer.push_back(m.first);
        } 
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
