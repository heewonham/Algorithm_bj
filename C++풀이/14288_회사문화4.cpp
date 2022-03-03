#include <iostream>
#include <vector>

#define MAX 100002
#define DIV (1<<18)
using namespace std;
typedef long long LL;
struct st{
	int s;
	int e;
};

vector<int> emp[MAX];
int cnt = 1;
st sub[MAX];
LL tree[DIV], lazy[DIV];

void dfs(int idx){
	sub[idx].s = cnt++;
	for(int i = 0; i < emp[idx].size(); i++){
		dfs(emp[idx][i]);
	}
	sub[idx].e = cnt-1;
}
void lazy_update(int node, int s, int e){
	
	if(lazy[node]){
		tree[node] += lazy[node];
		if(s != e){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
}
LL query(int node, int s, int e, int idx){
	lazy_update(node, s, e);
	if(idx < s || e < idx) return 0;
	if(s == e) return tree[node];
	return query(node*2, s, (s+e)/2, idx) + query(node*2+1, (s+e)/2+1, e, idx);
}
void update(int node, int s, int e, int l, int r, LL val){
	
	if(r < s || e < l) return;
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

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	// 부하직원
	for(int i = 1; i <= n; i++){
		int a;
		scanf("%d", &a);
		if(i > 1){
			emp[a].push_back(i);
		}
	} 
	
	dfs(1);
	
	// query
	bool topDown = true;
	vector<int> answer;
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		//scanf("%d", &num);
		if(num == 1){
			// update
			int idx;
			LL val;
			//scanf("%d %d", &idx, &val);
			cin >> idx >> val;
			if(topDown){ // 부하방향으로 칭찬 릴레이 
				update(1,1,MAX,sub[idx].s, sub[idx].e, val);
			}else{ // 상사 방향으로 칭찬 릴레이 
				update(1,1,MAX,1,sub[idx].s,val);
			}
			
		} else if(num == 2){ // query
			int idx;
			//cin >> idx;
			scanf("%d", &idx);
			answer.push_back(query(1,1,MAX,sub[idx].s));
		} else{
			// 부하 -> 상사, 상사 ->부하 
			topDown = (!topDown);
		}
	}
	
	// print
	for(int i = 0; i < answer.size(); i++){
		printf("%d\n", answer[i]);
	}
}
