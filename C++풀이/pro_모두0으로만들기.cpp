#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long sum = 0;
void dfs(vector<int> con[], long long w[], int cur, int parent){
    // 자식으로 내려가기
    for(int i = 0; i < con[cur].size(); i++){
        if(con[cur][i] == parent) continue;
        dfs(con, w, con[cur][i], cur);
    }
    
    // 현재 값에서 부모로 올리기
    w[parent] += w[cur];
    sum += abs(w[cur]);
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    int sz = a.size();
    
    // init
    vector<int> connect[sz];
    long long b[sz];
    for(int i = 0; i < sz; i++){
        sum += a[i];
        b[i] = a[i];
    }
    
    // no answer case
    if(sum != 0) return -1;
    
    // connection
    for(int i = 0; i < edges.size(); i++){
        int e1 = edges[i][0];
        int e2 = edges[i][1];
        connect[e1].push_back(e2);
        connect[e2].push_back(e1);
    }
    
    // dfs
    dfs(connect, b, 0, 0);
    
    return sum;
}

