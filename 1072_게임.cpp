#include <iostream>
using namespace std;
/*
	주의점 : 
	정수 범위를 벗어날 수 있음. 
		1. x,y가 같은 경우 - 100프로
		2. x,y가 99프로인 경우 
	
	하나씩 올리면 --- 타임아웃 
	줄일 수 있는 방법 ???
		이분탐색 ---> 전체범위를 어떻게 설정할 것인지?
		1. 처음 주어진 x를 최대값으로 진행하거나
		2. 2x , y+x일 경우 가능하지 않을까? 
		 
*/
long x, y, z;
int main(){
	
	cin >> x >> y;
	
	z = y * 100 / x;
	
	// 예외 처리
	if( x == y || z == 99 ){
		cout << -1;
		return 0;
	} 
	
	// 실행
	long bottom = 1, top = 1000000000, mid;
	long ans = 1000000000;
	// top찾기
	/*while(((y + top) * 100 / (x + top)) <= z){
		top *= 2;
	}*/
	while(bottom <= top){
		mid = (bottom + top) / 2;
		// 예상  
		long nextz = (y + mid) * 100 / (x + mid);
		if(z < nextz){
			if(mid < ans) {
				ans = mid;
			}
			top = mid -1;
		}
		else{
			bottom = mid + 1;
		} 
	} 
	
	cout << ans;
}
