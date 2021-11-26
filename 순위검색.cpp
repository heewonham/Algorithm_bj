#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> m[3][2][2][2];
bool visited[3][2][2][2];
vector<string> strParsing(string str){
    vector<string> l;
    istringstream ss(str);
    string buf;

    while(getline(ss, buf, ' ')){
        if(buf.compare("and") != 0){
            l.push_back(buf);
        }
    }
    return l;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string,int> mp;
    mp["cpp"] = 0;
    mp["java"] = 1;
    mp["python"] = 2;
    mp["backend"] = 0;
    mp["frontend"] = 1;
    mp["junior"] = 0;
    mp["senior"] = 1;
    mp["chicken"] = 0;
    mp["pizza"] = 1;
    
    // 1. info list √ﬂ√‚
    for(string str : info){
        vector<string> l = strParsing(str);
        int a = mp[l[0]], b = mp[l[1]], c = mp[l[2]], d = mp[l[3]];
        m[a][b][c][d].push_back(stoi(l[4]));
    }
    
    // 2. query list cnt
    for(string str : query){
        vector<string> l = strParsing(str);
        vector<int> idx[4];
        for(int i = 0; i < 4; i++){
            if(l[i] == "-"){
                idx[i].push_back(0);
                idx[i].push_back(1);
                if(i == 0) idx[i].push_back(2);
            }
            else idx[i].push_back(mp[l[i]]);
        }
        
        int cnt = 0;
        for(int a : idx[0]){
            for(int b : idx[1]){
                for(int c : idx[2]){
                    for(int d : idx[3]){
                        if(!m[a][b][c][d].empty()){
                            if(l[4].compare("-") == 0) cnt += (int)m[a][b][c][d].size();
                            else{
                                if(!visited[a][b][c][d]){
                                    std::sort(m[a][b][c][d].begin(),m[a][b][c][d].end());
                                    visited[a][b][c][d] = true;
                                }
                                std::vector<int>::iterator it;
                                it = lower_bound(m[a][b][c][d].begin(), m[a][b][c][d].end(),stoi(l[4])); 
                                cnt += m[a][b][c][d].size() + m[a][b][c][d].begin() - it;
        }}}}}}
        answer.push_back(cnt);
    }
    return answer;
}
