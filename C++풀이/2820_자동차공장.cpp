#include <iostream>
#include <vector>
#define MAX 500005
#define DIV 1 << 20
#define START ((1<<19)-1)

using namespace std;
typedef long long LL;
struct st{
	int s;
	int e;
};

int n, m, cnt = 1;
LL tree[DIV], lazy[DIV], cost[MAX], recost[MAX];
vector<int> sub[MAX]; 	// 부하직원 
st emp[MAX];			// 리라벨링 시작과 끝

void dfs(int idx){
	emp[idx].s = cnt++;
	for(int i = 0; i < sub[idx].size(); i++) dfs(sub[idx][i]);
	emp[idx].e = cnt-1;
}
LL init(int node, int s, int e){
	if(s == e) return tree[node] = recost[s];
	else{
		init(node*2, s, (s+e)/2);
		init(node*2+1, (s+e)/2+1, e);
		return tree[node] = tree[node * 2] + tree[node*2+1];
	}
}
void lazy_update(int node, int s, int e){
	if(lazy[node]){
		tree[node] += lazy[node];
		if(s != e){
			lazy[node * 2] += lazy[node];
			lazy[node *2 +1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int s, int e, int l, int r, int val){
	lazy_update(node, s, e);
	if(r < s || e < l) return;
	if(l <= s && e <= r){
		tree[node] += val;
		if(s != e){
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	update(node*2, s, (s+e)/2, l, r, val);
	update(node*2+1, (s+e)/2+1, e, l, r, val);
}
LL query(int node, int s, int e, int idx){
	lazy_update(node, s, e);
	if(idx < s || e < idx) return 0;
	if(s == e) return tree[node];
	return query(node*2, s, (s+e)/2, idx)+ query(node*2+1, (s+e)/2+1, e, idx);
	
}
int main(){
	
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		if(i == 1) scanf("%lld", &cost[i]);
		else{
			int a;
			scanf("%lld %d", &cost[i], &a);
			sub[a].push_back(i);
		}
	}
	
	// DFS로 relabeling 
	dfs(1);
	for(int i = 1; i <= n; i++)
		recost[emp[i].s] = cost[i];
	init(1,1,MAX);
	
	// 질의시작 
	for(int i = 0; i < m; i++){
		char c; int a; LL b;
		scanf(" %c", &c);
		if(c == 'u'){
			scanf("%d", &a);
			printf("%lld\n", query(1,1,MAX,emp[a].s));
		}	
		else if(c == 'p'){
			scanf("%d %lld", &a, &b);
			update(1,1,MAX,(emp[a].s)+1,emp[a].e, b);
		}
	}
}
