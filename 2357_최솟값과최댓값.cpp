#include <iostream>

#define DIV 1 << 18
#define MAX 100005
#define NUM_MAX 1000000001

using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;

int n, m;
pii tree[DIV];
LL arr[MAX];
int init(int node, int s, int e){
	if(s == e) {
		return tree[node].second = tree[node].first = arr[s];
	}
	else{
		init(node * 2, s, (s+e)/2);
		init(node * 2 + 1, (s+e)/2+1,e);
		tree[node].first = min(tree[node*2].first, tree[node*2+1].first);
		tree[node].second = max(tree[node*2].second, tree[node*2+1].second);
		return 0;
	}
}
pii query(int node, int s, int e, int l, int r){
	
	if(r < s || e < l) return pii(NUM_MAX,0);
	if(l <= s && e <= r) return tree[node];
	else{
		pii a = query(node*2, s, (s+e)/2, l, r);
		pii b = query(node*2+1, (s+e)/2+1, e, l, r);
		LL min_n = a.first < b.first ? a.first : b.first;
		LL max_n = a.second < b.second ? b.second : a.second;
		return pii(min_n,max_n);
	}
	
}
int main(){
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", (&arr[i]));
	}
	
	init(1,1,MAX);
	
	for(int i = 0 ; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		pii ans = query(1,1,MAX,a,b);
		printf("%lld %lld\n", ans.first, ans.second);
	}
	
	return 0;
} 
