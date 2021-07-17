#include <iostream>
#include <vector>
#include <algorithm>
#define P 1<<12
using namespace std;
typedef pair<int,int> pii;
struct st {
	int a,b;
};

int n, m;
vector<pii> node;
int tree[P*2] = {0,};
void update(int d)
{
	d += P;
	tree[d]++;
	d/=2;
	while(d)
	{
		tree[d]++;
		d/=2;
	}
}
int query(int l, int r)
{
	l += P, r += P;
    int ret = 0;
    while(l<=r)
    {
        if (l%2==1) ret += tree[l++];
        if (r%2==0) ret += tree[r--];
        l/=2, r/=2;
    }
    return ret; 
}
int main(){
	
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int s, d;
		cin >> s >> d;
		node.push_back(pii(s,d));
	}
	sort(node.begin(),node.end());
	
	long long ans = 0;
	for(int i =0; i < node.size(); i++){
		int d = node[i].second;
		ans += query(d+1,n);
		update(d);
	}
	cout << ans;
}
