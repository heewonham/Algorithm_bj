#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
typedef pair<int,int> pii;
int n;
vector<pii> player;
int tree[1<<19];
int compare(pii a, pii b){
	return a.second < b.second;
}
// ���׸�Ʈ Ʈ�� seg, update
int seg(int node, int s, int e, int l, int r){
	
	// ������ ������ ��� ���
	if(r < s || e < l) return 0;
	// ���� �̳��� ���
	if(l <= s && e <= r ) return tree[node];
	// ���� �ʰ��� ���	
	else{
		return seg(node * 2, s, (s+e)/2, l, r) + seg(node * 2 + 1, (s+e) / 2 + 1, e, l, r);
	}
}
void update(int node, int s, int e, int idx, int val){
	
	// ������ ������ ��� ���
	if(idx < s || idx > e) return;
	// �� �̻� ������ ��尡 ���� ��� 
	if(s == e) tree[node] = val;
	// Ȯ���� �ʿ��� ���
	else{
		update(node * 2, s, (s+e)/2, idx, val);
		update(node * 2 + 1, (s+e)/2 + 1, e, idx, val);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	
}
int main(){
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		int power;
		cin >> power;
		player.push_back(pii(i,power));
	}
	
	// power�� relabeling
	sort(player.begin(), player.end(), compare);
	for(int i = 0; i < n; i++){
		player[i].second = i+1;
	}
	
	// �ٽ� ���� ������� sort 
	sort(player.begin(), player.end());

	for(int i = 0; i < n; i++){
		int cnt = 0;
		int cur = player[i].second;
		if(cur > 1)
			cnt = seg(1,1,n,1,cur-1);
		// update 
		update(1,1,n,cur,1);
		cout << i + 1 - cnt << '\n';
	}
}

//	for(int i = 0; i < n; i++){
//		printf("%d %d\n",player[i].first, player[i].second);
//	}
