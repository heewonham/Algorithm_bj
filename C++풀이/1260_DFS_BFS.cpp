#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
bool visited1[1005];
bool visited2[1005];
vector<int> vertex[1005];

void DFS(int s) {
	
	printf("%d ",s);
	visited1[s] = true;

	for (int i = 0; i < vertex[s].size(); i++) {
		int x = vertex[s][i];
		if (!visited1[x]) DFS(x);
	}
}
void BFS(int s){
	
	queue<int> que;
	que.push(s);
	visited2[s] = true;

	while (!que.empty()) {
		int x = que.front();
		que.pop();
		printf("%d ",x);

		for (int i = 0; i < vertex[x].size(); i++) {
			int y = vertex[x][i];
			if (!visited2[y]) {
				que.push(y);
				visited2[y] = true;
			}
		}
	}
}
int main() {
	int i,s,f;
	int n,m,v;
	scanf("%d %d %d", &n, &m, &v);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &s, &f);
		vertex[s].push_back(f);
		vertex[f].push_back(s);
	}

	for (i = 1; i <= n; i++) {
		sort(vertex[i].begin(), vertex[i].end()); // ¿À¸§Â÷¼ø Á¤·Ä
	}

	// 1. DFS(±íÀÌÅ½»ö)
	DFS(v);
	printf("\n");
	
	// 2. BFS(³ÊºñÅ½»ö) - queue
	BFS(v);
}

