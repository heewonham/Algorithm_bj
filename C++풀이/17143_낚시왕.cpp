#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;

struct pos{
	int r, c;
};
struct shark{
	int s, d, z;
};
int R, C, M;
int sum = 0;
shark matrix[101][101][101];
queue<pos> q;
/*
	방향 : 1 행부분 움직임 -
		   2 행부분 움직이 +
		   3 열부분 움직임 +
		   4 열부분 움직임 -
*/
void shark_mv(pos p, shark s, int idx){
	
	int cnt, nr, nc, nd = s.d;
	cnt = (s.d <= 2)? s.s%((R-1) *2) : s.s%((C-1) *2);
	
	if(cnt == 0){
		nr = p.r; nc = p.c;
	}
	else if(s.d == 1){
		if(p.r - 1 >= cnt) nr = p.r - cnt;
		else{
			cnt -= p.r - 1; nd = 2;
			if(R - 1 >= cnt) nr = 1 + cnt;
			else{
				nd = 1;
				cnt -= R - 1;
				nr = R - cnt;
		}	}
		nc = p.c;
	}
	else if(s.d == 2){
		if(R - p.r >= cnt) nr = p.r + cnt;
		else{
			cnt -= R - p.r; nd = 1;
			if(R - 1 >= cnt) nr = R - cnt;
			else{
				nd = 2;
				cnt -= R - 1;
				nr = 1 + cnt;
		}	}
		nc = p.c;
	}
	else if(s.d == 3){
		if(C - p.c >= cnt) nc = p.c + cnt;
		else{
			cnt -= C - p.c; nd = 4;
			if(C - 1 >= cnt) nc = C - cnt;
			else{
				nd = 3;
				cnt -= C - 1;
				nc = 1 + cnt;
		}	}
		nr = p.r;
	}
	else{
		if(p.c - 1 >= cnt) nc = p.c - cnt;
		else{
			cnt -= p.c - 1; nd = 3;
			if(C - 1 >= cnt) nc = 1 + cnt;
			else{
				nd = 4;
				cnt -= C - 1;
				nc = C - cnt;
		} 	}
		nr = p.r;
	}
	
	// 다음 상어 이동 정렬 
	if(matrix[nr][nc][idx].d != 0){
		// 이미 있음 , 큰거 집어넣음
		if(matrix[nr][nc][idx].z < s.z)
			matrix[nr][nc][idx] = shark{s.s,nd,s.z};
	}
	else{
		matrix[nr][nc][idx] = shark{s.s,nd,s.z};
		q.push(pos{nr,nc});
	}
}
void fishing(int idx){
	
	int cnt = q.size();
	queue<pos> tmp;
	pos near;
	int pow = 0; 
	while(cnt){
		pos pos = q.front(); q.pop();
		if(pos.c == idx){ // 잡을 수 있음. 
			tmp.push(pos);
			if(pow == 0 || near.r > pos.r){
				near = pos; pow = matrix[pos.r][pos.c][idx-1].z;
			}
		} 
		else{ // 다른 상어는 움직임 
			shark_mv(pos,matrix[pos.r][pos.c][idx-1], idx);
		}
		cnt--;
	}
	
	// 잡음 + 나머지는 움직임
	while(!tmp.empty()){
		pos pos = tmp.front(); tmp.pop();
		if(near.r == pos.r) continue;
		shark_mv(pos,matrix[pos.r][pos.c][idx-1], idx);
	}
	sum += pow;
}
int main(){
	
	scanf("%d %d %d", &R, &C, &M);
	
	for(int i = 0; i < M; i++){
		int r, c, s, d, z;
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		q.push(pos{r,c});
		matrix[r][c][0] = shark{s,d,z};
	}
	
	// 낚시꾼 이동 
	for(int i = 0; i < C; i++){
		// 낚시 
		fishing(i+1); 		
	}
	
	// 출력
	printf("%d", sum); 
}
