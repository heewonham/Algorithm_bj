#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

string island[51];
bool visited[51][51];
int c, r, answer = 0;
int mc[] = {0,0,1,-1}, mr[] = {1,-1,0,0};
struct st{
	int c;
	int r;
	int time;
};
void bfs(int cc, int rr){
	
	queue<st> q;
	q.push(st{cc,rr,0});
	visited[cc][rr] = true;
	
	while(!q.empty()){
		
		int curr_c = q.front().c;
		int curr_r = q.front().r;
		int time = q.front().time;
		q.pop();
		
		// 가장 오래된 시간 갱신 
		if(time > answer) answer = time;
		
		// 이동 
		for(int i = 0; i < 4; i++){
			int next_c = curr_c+mc[i], next_r = curr_r +mr[i];
			if(next_c < 0 || next_c >= c || next_r < 0 || next_r >= r) continue;	
			if(!visited[next_c][next_r]&& island[next_c][next_r] == 'L'){
				visited[next_c][next_r] = true;
				q.push(st{next_c,next_r,time+1});
			}
			
		}
	}

}
void init(){
	
	for(int i = 0; i < 51; i++){
		memset(visited[i],false,sizeof(bool)*51);
	}
	
}
int main(){
	scanf("%d %d", &c, &r);
	
	for(int i = 0; i < c; i++)
		cin >> island[i];
		
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			if(island[i][j] == 'L'){
				bfs(i,j);
				init();
			}
		}
	}
	
	cout << answer;
}
