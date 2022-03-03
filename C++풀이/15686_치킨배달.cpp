/*
	N*N 크기의 도시
	치킨거리 구하기 :
		(x1,y1), (x2,y2) = |x1 - x2| + |y1 - y2|
		모든 집의 치킨 거리 합이 최소 
		
	m은 남아있는 치킨집
	1은 집, 2는 치킨집
	
	생각해보아야 할 것 :
		1. 어떤 치킨집을 폐업시켜야하나?
			거리를 저장하고, 짧으면 갱신 후 치킨집 저장
			그리고 bfs로 선택?
			가지 치기로 이미 최소를 넘어가면 return 
		
		최악으로 계산
		50 * 50 에
			치킨집은 13, 집은 100개 
		2. 거리를 저장 
	 
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
	
	// 현재 방문 
	int x = chick[idx].first;
	int y = chick[idx].second;
	
	queue<pii> back;
	queue<int> num;
	
	// 하우스 거리 측정 
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
	
	// 현재 방문 x 다음으로 넘어감  - 삭제후 
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
	
	// 초기화 작업
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dist[i][j] = 99;
		}
	} 
	
	// 진행
	promising(0,0,0);

	// 출력
	cout << ans; 
} 
