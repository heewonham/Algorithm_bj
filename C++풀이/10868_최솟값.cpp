#include <iostream>
#define DIV 1<<18
#define MAX 100005
#define NUM_MAX 1000000001
using namespace std;
typedef long long LL;

LL tree[DIV];
LL arr[MAX];
// 재귀함수로 바로 처리함. 
int init(int node, int s, int e){
	
	if(s == e) return tree[node] = arr[s];
	else{
		init(node * 2, s, (s+e)/2);
		init(node * 2 + 1, (s+e)/2+1,e);
		return tree[node] = min(tree[node*2], tree[node*2+1]);
	}
}
LL query(int node, int s, int e, int l, int r){
	// 범위 초과 
	if(r < s || e < l) return NUM_MAX;
	if(l <= s && e <= r) return tree[node];
	else{
		int a = query(node * 2, s, (s+e)/2, l, r);
		int b = query(node * 2 + 1, (s+e)/2+1, e, l,r);
		return a > b ? b : a;
	}
}
int main(){
	
	int n,m;
	scanf("%d %d\n", &n, &m);
	
	// 입력 
	for(int i = 1; i <= n; i++)
		scanf("%d\n", &(arr[i]));
		
	init(1,1,MAX);
	
	// 최솟값 찾기
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n",query(1,1,MAX,a,b));
	}
	
	return 0;
}
