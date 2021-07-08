#include <iostream>

int n, m, limit;
int ans, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char board[50][51];
int max_b[50][50]; 	// ���ۺ��� ���� ���� ������ Ƚ�� ��� 
using namespace std;
/*  1. �⺻ �̵� 
	2. �������� ���ܰ� ó�� - �ִ밪�� Ȱ��
	3. �ʹ� ���� ���ư� - ���� �� �ִ� ��� ???
		�迭�� �Դ� ���� �ִ밪�� �����Ѵ�. (����) 
*/

void dfs(int y, int x, int cnt){

	if(ans < cnt) ans = cnt;
	if(ans > limit) return;	// �ִ밪�� �ʰ��� ���
	
	// ����ó��
	if(y < 0 || n <= y || x < 0 || m <= x || board[y][x] == -1) return; 	
	
	if(max_b[y][x] >= cnt) return; // �ִ� �̵���ΰ� �����Ƿ� ���� �� �ʿ����
	max_b[y][x] = cnt;
	
	// �̵�ó�� 
	int mul = board[y][x];
	for(int i =0; i < 4; i ++){
		dfs(y +dy[i] * mul, x + dx[i] * mul, cnt + 1); 
		
	} 
}

int main(){
	
	// 1. �Է� 
	cin >> n >> m;
	
	// �ִ밪 ����
	limit = n * m;
	
	// ����� - -1�� �ʱ�ȭ
	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			max_b[i][j] = -1;
		}
	} 
	
	// ������ �Է� (���ڷ� ����) 
	for(int i=0; i < n; i++){
		cin >> board[i];
		for(int j =0; j<m; j++){
			if(board[i][j] == 'H') board[i][j] = -1;
			else board[i][j] -= '0'; // ���ڷ� ����� 
		}
	}
	
	// 2. ó��
	dfs(0,0,0);
	// ���� �ִ밪 �ʰ��� -1�� ���� 
	if(ans > limit) ans = -1;
	
	// 3. ���
	cout << ans; 
}
