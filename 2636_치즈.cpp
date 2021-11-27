#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int cnt = 0, n, m, hour = 0, time = 0;
int matrix[101][101];
bool visited[101][101];
int my[] = {0,0,1,-1}, mx[] = {1,-1,0,0};
struct st{
	int y;	int x;
};
void init(){
	for(int i = 0; i < m ; i++)
		memset(visited[i], false, sizeof(bool) * n);
}
int melting(int c){
	
	queue<st> q;
	int ct = c;
	q.push(st{0,0}); init();
	visited[0][0] = true;
	
	while(!q.empty() && ct){
		int y = q.front().y, x = q.front().x;
		q.pop();
		for(int i = 0; i < 4; i++){
			int xx = x + mx[i], yy = y + my[i];
			if(xx < 0 || xx > n || yy < 0 || yy > m) continue;
			if(!visited[yy][xx]){
				if(matrix[yy][xx] == 0)
					q.push(st{yy,xx});
				if(matrix[yy][xx] == 1){
					ct--; matrix[yy][xx] = 0; 
				}
				visited[yy][xx] = true;
			}
		}
	}
	return ct;
}
int main(){

	vector<st> cheese_list;
	cin >> m >> n;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &matrix[i][j]);
			if(matrix[i][j] == 1) cnt++;
		}
	}
	
	// 가장자리 찾기
	while(cnt){
		time++;
		hour = cnt;
		cnt = melting(hour);
	}

	cout << time << endl;
	cout << hour << endl;
}
