#include <iostream>
#include <vector>
using namespace std;

bool che[1000001];
int n, a[100];
vector<int> prime;
int count[100][80000];  // 대략 100만 이하 소수가 7xxxx개 있는데..... 
int p_c[80000] = {0, }, gcd_c[80000] = {0, };

int ans1 = 1, ans2 = 0;
int main() {
    for (int i = 2 ; i <= 1000000 ; i++) {
        if (che[i]) continue;
        else
        	prime.push_back(i);	
        // i is prime 
        for (int j = i + i ; j <= 1000000 ; j += i) {
            che[j] = true;
        }
    }
   
  	cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    // 소인수분해 
    for (int i = 0 ; i < n ; i++) {
        int num = a[i];
        for (int j = 0 ; j < prime.size() ; j++) {
            while (num % prime[j] == 0) {
                count[i][j]++;
                p_c[j]++;
                num /= prime[j];
            }
        }
    }

    // 자신에게 적은 것을 가져오기 
    for(int i = 0 ; i < prime.size(); i++) {
		gcd_c[i] = p_c[i] / n;
		int num = gcd_c[i];
		while(gcd_c[i] != 0 && num > 0){
			ans1 *= prime[i]; 
			num--;
		}
    }
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < prime.size(); j++){
    		if(gcd_c[j] > count[i][j]){
    			ans2 += gcd_c[j] - count[i][j];
			}
		}
	}
	
	cout << ans1 << " " << ans2;
}
