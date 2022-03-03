#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int matrix[505][505];
int dp[505][505];
bool visited[505][505];
int my[] = {0,0,1,-1}, mx[] = {1,-1,0,0};
int m, n;
struct st{
	int y;
	int x;
	int prev;
};
int dfs(int y, int x){
	
	if(y == m-1 && x == n-1) { return 1; }
	
	if(visited[y][x]) return dp[y][x];
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++){
		int next_y = y + my[i];
		int next_x = x + mx[i];
		if(next_y < 0 || next_x < 0 || next_y >= m || next_x >= n) continue;
		if(matrix[next_y][next_x] >= matrix[y][x]) continue;
		dp[y][x] += dfs(next_y,next_x);
	}
	
	return dp[y][x];
}
int main(){
	
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);		
		}
	} 
	
	dfs(0,0);
	printf("%d", dp[0][0]);
	
}
