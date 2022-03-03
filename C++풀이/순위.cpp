#include <string>
#include <vector>
#include <queue>

#define WIN 0
#define LOSE 1
using namespace std;

int r[101][2];
bool visited[101][101][2];
vector<int> winner[101], loser[101];

void chk(int i){
	queue<int> q; q.push(i);
    while(!q.empty()){
        int idx = q.front(); q.pop();
        for(int j : winner[idx]){
            if(!visited[i][j][WIN]){
                visited[i][j][WIN] = true;
                r[i][WIN]++;
                q.push(j);
            }
        }
    }
    q.push(i);
    while(!q.empty()){
        int idx = q.front(); q.pop();
        for(int j : loser[idx]){
            if(!visited[i][j][LOSE]){
                visited[i][j][LOSE] = true;
                r[i][LOSE]++;
                q.push(j);
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    if(n == 1) return 1;
    for(int i = 0; i < results.size(); i++){
        winner[results[i][WIN]].push_back(results[i][LOSE]);
        loser[results[i][LOSE]].push_back(results[i][WIN]);
    }
    
    for(int i = 1; i <= n; i++){
        // win & lose chk
        chk(i);
        if((r[i][WIN]+r[i][LOSE]) == n-1) answer++;
    }
    return answer;
}
