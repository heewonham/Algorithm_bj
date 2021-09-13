#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
bool visited[200];

void dfs(int idx, vector<vector<int>> computers){
    
    queue<int> q;
    q.push(idx);
    
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        
        for(int i = 0; i < computers[pos].size(); i++){
            if(pos != i && computers[pos][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    return;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < computers.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}
