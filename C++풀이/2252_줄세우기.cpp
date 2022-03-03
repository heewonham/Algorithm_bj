#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int num[32001] = {0, };
int main(){
	
	cin >> n >> m;
	vector<int> height[n+1];
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		height[a].push_back(b);
		num[b]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(num[i] == 0){
			q.push(i);
		}
	}
	
	// ¼ø¼­
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int j = 0; j < height[v].size(); j++){
			int node = height[v][j];
			num[node]--;
			if(num[node] == 0)
				q.push(node);			
		}
		cout << v << " ";
	}
}
