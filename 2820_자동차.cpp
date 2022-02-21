#include <iostream>
#include <vector>

#define PIV (1<<19)
#define MAX 500002
using namespace std;

typedef long long LL;
struct st {
	int start;
	int end;
};

LL tree[PIV*2], lazy[PIV*2];
LL cost[MAX], recost[MAX];
vector<int> sub[MAX]; //누구의 부하인지 지정 
st emp[MAX]; // 부하의 범위를 지정 
int cnt = 1;

void dfs(int idx);
LL query(int node, int s, int e, int idx);
void lazy_update(int node, int s, int e);
void update(int node, int s, int e, int l, int r, int val);

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		if(i == 1) scanf("%lld", &cost[i]);
		else{
			int a;
			scanf("%lld %d", &cost[i], &a);
			sub[a].push_back(i);
		}
	}
	
	/* 부하 범위를 지정후 다시 relabeling*/
	dfs(1);
	for(int i = 1; i <= n; i++){
		recost[emp[i].start] = cost[i];
		tree[PIV + emp[i].start -1] = cost[i];
	}
	
	for(int i = 0; i < m; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == 'u'){
			int idx;
			scanf("%d", &idx);
			printf("%lld\n", query(1,1,MAX,emp[idx].start));
		} else{
			int em, val;
			scanf("%d %d", &em, &val);
			update(1,1,MAX,emp[em].start+1, emp[em].end, val);
		}
	}
	
}
void dfs(int idx){
	emp[idx].start = cnt++;
	// 밑에 부하들 
	for(int i = 0; i < sub[idx].size(); i++){
		dfs(sub[idx][i]);
	}
	emp[idx].end = cnt-1;
}
LL query(int node, int s, int e, int idx){
	lazy_update(node,s,e);
	if(idx < s || e < idx) return 0;
	if(s == e) return tree[node];
	return (query(node*2, s, (s+e)/2, idx) + 
		query(node*2+1, (s+e)/2+1, e, idx)); 
}
void lazy_update(int node, int s, int e){
	if(lazy[node]){
		tree[node] += lazy[node];
		if(s != e){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int s, int e, int l, int r, int val){
	lazy_update(node, s, e);
	if(r < s || e < l) return;
	// l ~ r 사이에 s ~ e가 있는 경우 
	if(l <= s && e <= r){
		tree[node] += val;
		if(s != e){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return;
	}
	update(node*2, s, (s+e)/2, l, r, val);
	update(node*2+1, (s+e)/2+1, e, l, r, val);
}
