#include <iostream>
#include <queue>
#include <deque> 
using namespace std;
typedef pair<int, int> pii_int;
typedef pair<int, char> pii_char;

int n, k, l, cur_dir = 3;
deque<pii_int> snack;  // 뱀의 위치 기록한 vector
int map[101][101]; // 전체 matrix 
// 현재 방향, 그방향에 따른 방향 변환 , 상하좌우( D 오른쪽 , L 왼쪽
queue<pii_char> next_dir;  
int dir_x[4] = {0,0,-1,1}, dir_y[4] = {-1,1,0,0};
int dir_L[4] = {2,3,1,0}, dir_D[4] = {3,2,0,1}; 

int dummy(){
	
	int cnt = 0;
	snack.push_front(pii_int(1,1));
	map[1][1] = 2; 
	while(1){
		
		// 방향 변경여부 
		if(next_dir.front().first == cnt){
			if(next_dir.front().second == 'L')
				cur_dir = dir_L[cur_dir];
			else
			 	cur_dir = dir_D[cur_dir];
			next_dir.pop();
		} 
		
		// 이동 
		int next_x = snack.front().second + dir_x[cur_dir];
		int next_y = snack.front().first + dir_y[cur_dir];
		cnt++;
		 
		// 벽에 붙으면..  
		if(next_x <= 0 || next_y <= 0 || next_x > n || next_y > n ) return cnt;
		// 뱀 몸통에 붙으면 ..
		if(map[next_y][next_x] == 2) return cnt;
		// 사과 있는지? 
		if(map[next_y][next_x] != 1) { // 전체 움직임
			map[snack.back().first][snack.back().second] = 0;
			snack.pop_back();
		}
		map[next_y][next_x] = 2;
		snack.push_front(pii_int(next_y,next_x));
	}
	
	return cnt;
} 
int main(){
	
	scanf("%d %d", &n, &k);
	int y, x; char d;
	for(int i = 0; i < k; i++){
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
	}
	scanf("%d", &l);
	for(int i = 0; i < l; i++){
		cin >> x >> d;
		next_dir.push(pii_char(x,d));
	}
	
	printf("%d", dummy());	
}
