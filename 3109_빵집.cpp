#include <iostream>
using namespace std;

int R, C, my[] = {-1,0,1};
char matrix[10000][501];
bool visited[10000][501];

int dfs(int y, int x){
	
	if(x == C-1) return 1;
	
	for(int i = 0; i < 3; i++){
		int next_y = y+my[i], next_x = x+1;
		if(next_y >= 0 && next_y < R && !visited[next_y][next_x] && matrix[next_y][next_x] == '.'){
			visited[next_y][next_x] = true;
			if(dfs(next_y, next_x)) return 1;
		}
	}
	
	return 0;
	
}
int main(){
	ios::sync_with_stdio(false);
	 
	int cnt = 0;
	scanf("%d %d", &R, &C);
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			scanf(" %c", &matrix[i][j]);
		}
	}
	
	for(int i = 0; i < R; i++){
		cnt += dfs(i,0);
	}
	
	printf("%d", cnt);
}
