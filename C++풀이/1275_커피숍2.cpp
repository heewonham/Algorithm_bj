#include <iostream>
#define LEV (1<<17)
#define MAX 100005
using namespace std;

typedef long long LL;
LL tree[LEV*2];
LL arr[MAX];
LL init(int node, int s, int e, int idx, LL val){
	
	if(idx < s || idx > e) return 0;
	if(s == e) return tree[node] = val;
	else{
		init(node*2,s,(s+e)/2,idx,val) + init(node*2+1,(s+e)/2+1,e,idx,val);
		return tree[node] = tree[node * 2] + tree[node * 2 +1];
	}
}
void update(int node, int s, int e, int idx, LL diff){
	
	if(idx < s || e < idx) return;
	tree[node] += diff;
	if(s != e){
		update(node * 2, s, (s+e)/2, idx, diff );
		update(node * 2 + 1 , (s+e)/2+1, e, idx, diff);
	}
}
LL query(int node, int s, int e, int l, int r){
	
	if(r < s || e < l) return 0;
	if(l <= s && e <= r) return tree[node];
	else{
		return query(node *2, s, (s+e)/2, l,r) + query(node * 2+1, (s+e)/2+1, e, l, r);
	}
}
int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%lld ", &arr[i]);
		init(1,1, MAX, i, arr[i]);
	}

	for(int i = 0; i < q; i++){
		int x, y;
		LL a, b;
		scanf("%d %d %lld %lld",&x,&y,&a,&b);
		if(x > y)
			printf("%lld\n",query(1,1,MAX,y,x));
		else	
			printf("%lld\n",query(1,1,MAX,x,y));
		LL diff = b - arr[a];
		arr[a] = b;
		update(1,1,MAX,a,diff); 
	}	
}
