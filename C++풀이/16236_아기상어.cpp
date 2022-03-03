#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int movex[] = {0,-1,1,0}, movey[] = {-1,0,0,1};
int sea[20][20], fish[7], n, total = 0;
bool visited[20][20];
struct st{
	int y;
	int x;
	int move_cnt;
};
struct sk{
	int x;
	int y;
	int eat;
	int pow;
	
};
sk shark = {0,0,0,2};
void update(){
	shark.eat++;
	if(shark.pow < 7 && shark.eat >= shark.pow){
		shark.pow++;
		shark.eat = 0;
	}	
}
void init(int y, int x){
	
	for(int i = 0; i < n; i++){
		memset(visited[i],false,20);
	}
	visited[y][x] = true;
}
int bfs(int y, int x, int mv){
	
	int min_x = -1, min_y = -1, min_m = -1;
	bool chk = false;
	init(y,x);
	queue<st> q;
	q.push(st{y,x,mv});
	if(total < mv) total = mv;
	
	while(!q.empty()){
		
		int sy = q.front().y;
		int sx = q.front().x;
		int m = q.front().move_cnt;
		q.pop();
		
		// 가장 위쪽 그리고 왼쪽으로 이동 
		if(chk && min_m < m){
			fish[sea[min_y][min_x]]--;
			update();
			sea[min_y][min_x] = 0;
			return bfs(min_y,min_x,min_m);
		}
		
		// 이제 먹을게 없음
		int cnt = 0;
		for(int i = 1; i < shark.pow; i++)
			cnt += fish[i];
		if(cnt == 0) return m;
				
		// 돌아댕기기 
		for(int i = 0; i < 4; i++){
			int xx = sx + movex[i];
			int yy = sy + movey[i];
			if(xx < 0 || xx >= n || yy < 0 || yy >= n || visited[yy][xx] || sea[yy][xx] > shark.pow) continue;
			visited[yy][xx] = true;
			q.push(st{yy,xx,m+1});
			// 먹을 수 있는 피시 중 가장 위쪽이면서 왼쪽인 좌표를 저장
			if(sea[yy][xx] != 0 && sea[yy][xx] < shark.pow){
				if(!chk) min_x = xx, min_y = yy, min_m = m+1, chk = true;
				else if(chk && min_m >= m+1){
					if(min_y > yy || (min_y == yy && min_x > xx))
						min_x = xx, min_y = yy, min_m = m+1;
				}
			}
		}
	}
	
	if(chk){
		fish[sea[min_y][min_x]]--;
		update();
		sea[min_y][min_x] = 0;
		return bfs(min_y,min_x,min_m);
	}
	return 0;
}
int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &sea[i][j]);
			if(sea[i][j] != 9) fish[sea[i][j]]++;
			else{
				shark.x = j, shark.y = i;
				sea[i][j] = 0;
			}
		}
	}
	
	bfs(shark.y, shark.x, 0);
	printf("%d",total);
}
