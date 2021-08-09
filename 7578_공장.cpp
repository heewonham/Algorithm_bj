#include <iostream>
#define DIV 1 << 20
#define M_MAX 1000005
#define IDEN_MAX 500005

using namespace std;
typedef long long LL;
int n;
int machine[M_MAX];
LL tree[DIV];
// 저장된 기계도 반환하면서 동시에 업데이트 
LL seg(int node, int s, int e, int idx){
	
	if(idx < s || e < idx ) return 0;
	if(s == e)
		return tree[node] += 1;
	else{
		seg(node * 2, s, (s+e)/2, idx);
		seg(node * 2 + 1, (s+e)/2+1, e, idx);
		return tree[node] = tree[node*2] + tree[node*2+1];
	}
}
LL query(int node, int s, int e, int l, int r){
	
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return tree[node];
	else{
		return query(node * 2, s, (s+e)/2, l, r) + query(node * 2 + 1, (s+e)/2+1, e, l ,r);
	}
}
int main(){
	
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		machine[num] = i;
	}
	
	LL cnt = 0;
	for(int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		cnt += query(1,1,IDEN_MAX,machine[num],n);
		seg(1,1,IDEN_MAX,machine[num]);
	}
	
	printf("%lld", cnt);
	return 0;
} 
