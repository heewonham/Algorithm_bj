#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, K, parent[100001];
bool visited[100001];
vector<int> answer;
struct st{
	int num;
	int cnt;
};
int bfs(){
	
	queue<st> q;
	q.push(st{N,0});
	visited[N] = true;
	
	while(!q.empty()){
		int n = q.front().num;
		int c = q.front().cnt;
		q.pop();

		if(n == K){
			int par = n;
			while(par != N){
				answer.push_back(par);
				par = parent[par];
			}
			answer.push_back(par);
			return c;
		}
		
		if(n-1 >= 0 && !visited[n-1]){
			visited[n-1] = true;
			parent[n-1] = n;
			q.push(st{n-1,c+1});
		}
		if(n+1 <= 100000 && !visited[n+1]){
			visited[n+1] = true;
			parent[n+1] = n;
			q.push(st{n+1,c+1});
		} 
		if(n*2 <= 100000 && !visited[n*2]){
			visited[n*2] = true;
			parent[n*2] = n;
			q.push(st{n*2,c+1});
		}
	}
	
	return 1;
}
int main(){
	
	scanf("%d %d", &N, &K);

	printf("%d\n", bfs());
	for(int i = answer.size()-1; i >= 0; i--){
		printf("%d ", answer[i]);
	}
	return 0;
}
