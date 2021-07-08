#include <iostream>

int n, m, limit;
int ans, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char board[50][51];
int max_b[50][50]; 	// 시작부터 가장 많이 점프한 횟수 기록 
using namespace std;
/*  1. 기본 이동 
	2. 루프도는 예외값 처리 - 최대값을 활용
	3. 너무 많이 돌아감 - 줄일 수 있는 방법 ???
		배열에 왔던 것의 최대값을 저장한다. (갱신) 
*/

void dfs(int y, int x, int cnt){

	if(ans < cnt) ans = cnt;
	if(ans > limit) return;	// 최대값을 초과할 경우
	
	// 예외처리
	if(y < 0 || n <= y || x < 0 || m <= x || board[y][x] == -1) return; 	
	
	if(max_b[y][x] >= cnt) return; // 최대 이동경로가 있으므로 굳이 돌 필요없음
	max_b[y][x] = cnt;
	
	// 이동처리 
	int mul = board[y][x];
	for(int i =0; i < 4; i ++){
		dfs(y +dy[i] * mul, x + dx[i] * mul, cnt + 1); 
		
	} 
}

int main(){
	
	// 1. 입력 
	cin >> n >> m;
	
	// 최대값 설정
	limit = n * m;
	
	// 기록장 - -1로 초기화
	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			max_b[i][j] = -1;
		}
	} 
	
	// 보드장 입력 (숫자로 변경) 
	for(int i=0; i < n; i++){
		cin >> board[i];
		for(int j =0; j<m; j++){
			if(board[i][j] == 'H') board[i][j] = -1;
			else board[i][j] -= '0'; // 숫자로 만들기 
		}
	}
	
	// 2. 처리
	dfs(0,0,0);
	// 예외 최대값 초과면 -1로 변경 
	if(ans > limit) ans = -1;
	
	// 3. 출력
	cout << ans; 
}
