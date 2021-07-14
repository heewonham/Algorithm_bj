#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int n, m;
bool chk[1001] = {false, };
int p[1001];
vector<pair<pii,int>> node;
int compare(pair<pii,int> a, pair<pii,int> b){
	return a.second < b.second;
}
int find(int n)
{
	if(p[n] == n) return n;
	return p[n] = find(p[n]);
}
void uni(int a, int b)
{
	int c = find(a), d = find(b);
	if(c < d) p[d] = c;
	else p[c] = d;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i < n; i++)
		p[i] = i;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		node.push_back(make_pair(pii(a,b),c));
 	}
 	sort(node.begin(),node.end(),compare);

	int cnt = 0;
	int sum = 0;
 	for(int i = 0; i < m; i++){
		int a = node[i].first.first;
		int b = node[i].first.second;
		if(find(a) != find(b)){
			uni(a,b);
			cnt++;
			sum += node[i].second;
		}
		if(cnt == n-1) break;
 	}
 	
 	cout << sum;
}
