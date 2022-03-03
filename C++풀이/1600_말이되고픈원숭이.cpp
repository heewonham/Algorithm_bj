/*
	원숭이는 말처럼 이동 가능 단 , k번만 
	x-2,y+1 / x-1,y+2 / x+1,y+2, x+2,y+1
	x-2,y-1 / x-1,y-2 / x+1,y-2, x+2,y-1 
*/
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int k, w, h;
int maps[200][200];
bool visited[200][200][31] = {false,};
int answer = -1;
int x[] = {1,-1,0,0}, y[] = {0,0,1,-1};
int hx[] = {-2,-1,1,2,-2,-1,1,2}, hy[] = {1,2,2,1,-1,-2,-2,-1};
void bfs(int a, int b){
	
	queue<pair<pii, pii>> p;
	p.push(make_pair(pii(a,b),pii(0,0)));
	visited[0][0][0] = true;
	while(!p.empty())
	{
		int x1 = p.front().first.first;
		int y1 = p.front().first.second;
		int k1 = p.front().second.first;
		int move = p.front().second.second;
		p.pop();
		
		if(x1 == h-1 && y1 == w-1){
			answer = move;
			break;
		}
		
		// 원숭이 이동 
		for(int i = 0; i < 4; i++){
			int x2 = x1 + x[i], y2 = y1 + y[i];
			if(x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) continue;
			if(!visited[x2][y2][k1] && maps[x2][y2] != 1){
				visited[x2][y2][k1] = true;
				p.push(make_pair(pii(x2,y2),pii(k1,move+1)));
			}
		}
		
		// 말 이동 
		if(k1 < k){
			for(int i = 0; i < 8; i++){
				int x2 = x1 + hx[i], y2 = y1 + hy[i];
				if(x2 < 0 || y2 < 0 || x2 >= h || y2 >= w) continue;
				if(!visited[x2][y2][k1+1] && maps[x2][y2] != 1){
					visited[x2][y2][k1+1] = true;
					p.push(make_pair(pii(x2,y2),pii(k1+1,move+1)));
				}
			}			
		}	
	}
}
int main(){
	
	// 입력 
	cin >> k >> w >> h;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> maps[i][j];
		}
	}
	
	bfs(0,0);
	cout << answer;
}

