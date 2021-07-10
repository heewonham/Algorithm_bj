#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;

vector<int> a, b, c, d;
vector<int> ab, cd;
int n;
LL ans = 0;

int main(){
	
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
        int u, v, w, x;
        cin >> u >> v >> w >> x;
        a.push_back(u);
        b.push_back(v);
        c.push_back(w);
        d.push_back(x);
    }
    
    // a,b 로 만들수 있는 합의 조합 ==> ab
    // c,d로 만들수 있는 합의 조합 ==> cd
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }
	
	sort(ab.begin(),ab.end());
	sort(cd.begin(),cd.end());
	
	LL cnt = 0;
	int j = cd.size()-1;
	for(int i = 0; i < ab.size(); i++){
		int target = -ab[i];
		if(0 < i && ab[i] == ab[i-1]){
			ans += cnt;
			continue;
		}
		while(j >= 0 && target < cd[j]){
			j--;
		}
		cnt = 0;
		while(j >= 0 && target == cd[j]){
			j--;
			cnt++;
		}
		ans += cnt;
	}
 	cout << ans; 
}


