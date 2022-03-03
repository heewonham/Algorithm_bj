#include <iostream>
#define INF 1000000000
using namespace std;
typedef long long LL;
int n, m;
LL k;
LL tree[101][101];
char answer[201];
LL maketree(int a, int z)
{
	if(a == 0 || z == 0) return tree[a][z] = 1;
	if(tree[a][z]) return tree[a][z];
	tree[a][z] = maketree(a-1,z) + maketree(a,z-1); 
	if(tree[a][z] >= INF) tree[a][z] = INF;
	return tree[a][z];	
}
int main(){
	
	cin >> n >> m >> k;
	maketree(n,m);
	
	// 사전보다 작은 경우
	if(tree[n][m] < k){
		cout << -1;
		return 0;
	}
	
	
	// k번째 찾아가기
	int idx = 0;
	int a = n, z = m;
	while(idx < n+m){
		if(a == 0 || z == 0){
			if(a == 0) 
				answer[idx++] = 'z';
			else
				answer[idx++] = 'a';
		}
		else{
			//printf("tree[%d][%d] = %d\n",a-1,z,tree[a-1][z]);
			if(tree[a-1][z] < k){// z쪽 
				answer[idx++] = 'z';
				k -= tree[a-1][z];
				z -= 1;
			}
			else{ // a쪽 
				answer[idx++] = 'a';
				a -= 1;
			}
		}

		cout << answer[idx-1];
	}

}
