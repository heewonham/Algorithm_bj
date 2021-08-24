#include <iostream>
#include <vector>
#include <memory.h>

#define MAX 100001
#define DIV 1 << 19
#define START (1 << 18)-1
using namespace std;

int tree[DIV], lazy[DIV];
int test, n, m, ix;

int init(int node, int s, int e){
	
	if(s == e) return tree[node] = (MAX <= s && e <= n+100000)? 1:0;
	init(node*2, s, (s+e)/2);
	init(node*2+1,(s+e)/2+1,e);
	return tree[node] = tree[node*2] + tree[node*2+1];
	
}
int query(int node, int s, int e, int l, int r){
	
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return tree[node];
	return query(node*2, s, (s+e)/2, l, r) + query(node*2+1,(s+e)/2+1,e,l,r);

}
void update(int node, int s, int e, int idx, int val){
	
	tree[node] += val;
	if (s == e) return;
	if(s <= idx && (s+e)/2 >= idx)
		update(node*2, s, (s+e)/2, idx, val);
	else if((s+e)/2+1 <= idx && idx <= e)
		update(node*2+1, (s+e)/2+1, e, idx, val);
}
int main(){

	scanf("%d", &test);
	while(test--){
		
		// 초기화
		memset(lazy,0,DIV);
		memset(tree,0,DIV);
		int movie[MAX], s = 100001;
		 
		scanf("%d %d", &n, &m);

		for(int i = 1; i <= n; i++)
			movie[i] = 100000+i;
		
		init(1,1,MAX*2);	
		for(int i = 0; i < m; i++){
			scanf("%d", &ix);
			// 앞의 영화개수 출력 
			printf("%d ",query(1,1,MAX*2,1,movie[ix]-1));
			// 이동(tree에서 제거 및 순서 이동) 
			update(1,1,MAX*2,movie[ix], -1);
			movie[ix] = --s;
			update(1,1,MAX*2,movie[ix], 1);
		}
		printf("\n");
	}
}
