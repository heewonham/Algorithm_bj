#include <iostream>
#include <queue>
#include <vector>

#define MAX 100005
#define LEV 17
using namespace std;

int dept[MAX];
int parent[LEV][MAX];
vector<int> connect[MAX];
int n,m,x,y;
int lca(int a, int b){
	
	// a와 b node의 깊이를 맞춘다.
	int tmp;
	if(dept[a] > dept[b]){
		tmp = a;
		a = b;
		b = tmp;
	}
	
	// 그 높이로 이동
	tmp = dept[b] - dept[a];
	for(int i = 0 ; i < LEV; i++){
		int bit = 1 << i;
		if((tmp & bit) == bit){
			b = parent[i][b];
		}
	}
	
	if(a == b) return a;
	for(int i = LEV-1; i >= 0; i--){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	
	return parent[0][a];
}
int main(){
	
	// 노드 입력 
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &x, &y);
		connect[x].push_back(y);
		connect[y].push_back(x);
	}
	
	// 노드 연결
	queue<int> q;
	q.push(1); // 노드 번호
	q.push(1); // 노드 깊이
	while(!q.empty()){
		int num = q.front(); q.pop();
		int dep = q.front(); q.pop();
		dept[num] = dep;
		for(int i = 0; i < connect[num].size(); i++){
			int node = connect[num][i];
			
			if(dept[node] == 0){
				parent[0][node] = num;
				q.push(node);
				q.push(dep+1);
			}
		}
	}
	
	// 부모노드 연결
	for(int i = 1; i < LEV; i++){
		for(int j = 1; j <= n; j++ ){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
	
	// 답 찾기 
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", lca(x,y));
	}
} 
