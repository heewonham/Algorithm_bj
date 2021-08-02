#include <iostream>
#define LEV (1<<17)
using namespace std;

typedef long long LL;
LL tree[LEV * 2];
int n, q;
void update(int n, int v){
	n += LEV;
	tree[n] = v;
	n /= 2;
	while(n>0){
		tree[n] = tree[n *2] + tree[n*2+1];
		n /= 2;	
	}
}
LL query(int l, int r){
	
	l += LEV, r += LEV;
	LL res = 0;
	while(l <= r){
		if(l % 2 == 1) res += tree[l++];
		if(r % 2 == 0) res += tree[r--];
		l /= 2, r /= 2;
	}
	return res;
}
int main(){
	
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		update(i+1, val);
	}
	
	// ÅÏ °³¼ö
	for(int i = 0; i < q; i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if(x > y)
			cout << query(y,x) << '\n';
		else	
			cout << query(x,y) << '\n';
		update(a,b); 
	}	
}
