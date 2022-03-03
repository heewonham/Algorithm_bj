#include <iostream>
#define INF 1000000010
using namespace std;
int n,m,k;
 
char ans[201];
int cache[101][101] = {0, }; 
// a와 z의 개수 
int dic(int a, int z)
{
	// a가 0이거나 z가 0일 경우 더이상 진행이 불가 
	if(a == 0 || z == 0 )
		return 1;
	
	// 이미 방문한 경우  
	if(cache[a][z] != 0)
		return cache[a][z];
	
	// 경우의 수 개수를 저장하는 작업 
	cache[a][z] = dic(a -1, z) + dic(a, z-1);
	// 만약 저장된 경우의 수가 최대값인 10억을 초과할 경우
	// 굳이 10억 이상을 저장할 필요는 없다.
	if (cache[a][z] >= INF) {
    	cache[a][z] = INF;
    }
    return cache[a][z];
}

int main(){
	
	cin >> n >> m >> k;
	
	// 실행 및 k를 초과시  
	if(dic(n,m) < k){
		cout << -1;
		return 0;
	}
	
	// 출력 : 경우의 수 안에 있는 경우 탐색 
	int ac = n, zc = m; 
	for (int i = 0 ; i < n + m ; i++) {
    	if (ac > 0) {
            int tmp = dic(ac - 1, zc);
            if (tmp < k) {
                ans[i] = 'z';
                k -= tmp;
                zc--;
            }
            else {
                ans[i] = 'a';
                ac--;
            }
        }
        else ans[i] = 'z';
	}
	
	cout << ans;
}
