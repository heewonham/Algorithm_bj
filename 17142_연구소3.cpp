#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int lab[51][51];
int N, M, re = 0, answer = -1;
int mc[] = {0,0,1,-1}, mr[] = {1,-1,0,0};
bool visited[10], v[51][51];
struct st{
	int r;
	int c;
	int cnt;
};
vector<st> virus, vlist;

void init(){
	
	for(int i = 0; i < 51; i++){
		memset(v[i],false,sizeof(bool)*51);
	}
	
}
void bfs(){

	queue<st> q;
	int rm = re;
	init();
	
	for(int i = 0; i < vlist.size(); i++){
		q.push(vlist[i]);
		v[vlist[i].r][vlist[i].c] = true;
	}
	
	while(!q.empty()){
		int cc = q.front().c, rr = q.front().r, cnt = q.front().cnt;
		q.pop();
		
		if(answer != -1 && cnt > answer) return;
		
		for(int i = 0; i < 4; i++){
			int next_c = cc + mc[i], next_r = rr + mr[i];
			
			if(next_c < 0 || next_c >= N || next_r < 0 || next_r >= N) continue;
			if(lab[next_r][next_c] == 1) continue;
			
			if(!v[next_r][next_c]){
				v[next_r][next_c] = true;
				if(lab[next_r][next_c] == 0){
					rm--;
					if(rm == 0){
						if(answer == -1 || answer > cnt+1) answer = cnt+1; return; 
					}
				}
				q.push(st{next_r,next_c,cnt+1});
			}
		}
	}
}
void dfs(int idx, int ct){
	
	if(ct == M){
		for(int i = 0; i < virus.size(); i++){
			if(visited[i]) vlist.push_back(virus[i]);
		}
		bfs();
		vlist.clear();
		return;
	}
	
	for(int i = idx; i < virus.size(); i++){
		if(visited[i] == true) continue;
		visited[i] = true;
		dfs(i+1, ct+1);
		visited[i] = false;
	}
	
}
int main(){
	scanf("%d %d", &N, &M);
	
	// 입력 
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> lab[i][j];
			if(lab[i][j] == 0) re++;
			if(lab[i][j] == 2) virus.push_back(st{i,j,0});
		}
	}
	if(re == 0) { cout << 0; return 0;}
	
	// 실행 
	dfs(0, 0);

	// 출력 
	cout << answer;
}
