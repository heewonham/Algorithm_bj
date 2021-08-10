#include <iostream>
#define DIV (1 << 18)
#define MAX 65540
#define N_MAX 250005
/* 
	65536으로 세그먼트 트리 리프를 정하고,
	개수가 채워지면 그것의 중간값(5개면 2번째)을 찾아서 반환하고 
	처음 들어간 것을 제외하고 추가 
	!!!! 0~ 65536 임 범위 확인.. 필요... 
	
	예 : 
	7 7 9 9 9 10 6 8
	3 7 11 5 9 10 6 12 4 8  
*/
using namespace std;
typedef long long LL;
LL tree[DIV];
int arr[N_MAX];
void seg(int node, int s, int e, int idx, int val){
	
	if(idx < s || idx > e) return;
	if(s == e){
		tree[node] += val;
		return;
	}
	else if(s <= idx && idx <= e){
		tree[node] += val;
		seg(node * 2, s, (s+e)/2, idx, val);
		seg(node * 2 +1 , (s+e)/2+1, e, idx, val);
		return;
	}
}
LL query(int node, int s, int e, int idx){
	
	if(s == e) return s;
	if(tree[node * 2] >= idx){
		return query(node * 2, s, (s+e)/2, idx);
	}
	else{
		return query(node * 2+1, (s+e)/2+1, e, idx-tree[node * 2]);
	}
}
int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	int j = 1;
	int mid = ((k % 2) == 0)? (k/2) : ((k/2)+1);  
	LL ans = 0;
	for(int i = 1; i <= n; i++){
		
		scanf("%d", &(arr[i]));
		seg(1,1,MAX,arr[i]+1,1);
		
		if(i > k){
			seg(1,1,MAX,arr[j]+1,-1);
			j++; 
		}
			
		if(i >= k)
			ans += query(1,1,MAX,mid)-1;
	}
	
	printf("%lld", ans);	
} 
