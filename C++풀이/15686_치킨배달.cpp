/*
	N*N ũ���� ����
	ġŲ�Ÿ� ���ϱ� :
		(x1,y1), (x2,y2) = |x1 - x2| + |y1 - y2|
		��� ���� ġŲ �Ÿ� ���� �ּ� 
		
	m�� �����ִ� ġŲ��
	1�� ��, 2�� ġŲ��
	
	�����غ��ƾ� �� �� :
		1. � ġŲ���� ������Ѿ��ϳ�?
			�Ÿ��� �����ϰ�, ª���� ���� �� ġŲ�� ����
			�׸��� bfs�� ����?
			���� ġ��� �̹� �ּҸ� �Ѿ�� return 
		
		�־����� ���
		50 * 50 ��
			ġŲ���� 13, ���� 100�� 
		2. �Ÿ��� ���� 
	 
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n, m, ans = 9999;
vector<pii> chick;
vector<pii> house;
int dist[51][51];

void promising(int idx,int cnt, int sum){

	int s = sum;
	
	if(cnt >= m){
		if(sum != 0 && ans > sum) ans = sum;
		return;
	}
	if(idx >= chick.size()) return;
	
	// ���� �湮 
	int x = chick[idx].first;
	int y = chick[idx].second;
	
	queue<pii> back;
	queue<int> num;
	
	// �Ͽ콺 �Ÿ� ���� 
	for(int i = 0; i < house.size(); i++){
		int xx = house[i].first;
		int yy = house[i].second;
		
		int cal = abs(xx - x) + abs(yy - y);
		int prev = dist[xx][yy];
		
		if(prev > cal){
			if(prev != 99){
				s = s - prev;
			}
			back.push(pii(xx,yy));
			num.push(prev);
			dist[xx][yy] = cal;
			s += cal;
		}
	}
	
	promising(idx+1,cnt+1,s);
	
	// ���� �湮 x �������� �Ѿ  - ������ 
	while(!back.empty()){
		int n = num.front();
		int xx = back.front().first;
		int yy = back.front().second;
		back.pop();
		num.pop();
		
		dist[xx][yy] = n;
	}
	promising(idx+1,cnt, sum);

}
int main(){
	
	int tmp;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> tmp;
			if(tmp == 1)
				house.push_back(pii(i,j));
			else if(tmp == 2)
				chick.push_back(pii(i,j));
		}
	}
	
	// �ʱ�ȭ �۾�
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = 99;
		}
	} 
	
	// ����
	promising(0,0,0);

	// ���
	cout << ans; 
} 
