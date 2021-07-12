#include <iostream>
#include <vector>
using namespace std;

int test,n,m;
int cache[31][31];
vector<int> answer;
int nCr(int n, int r)
{
	if(r == 0) return 1;
	if(n < r || n > 30 || n < 0 || r > 30 || n < 0) return 0;	
	if(cache[n][r] != -1)
        return cache[n][r];
    
	cache[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
	return cache[n][r];
	
} 
int main(){
	
    for (int i = 0 ; i <= 30 ; i++) {
        for (int j = 0 ; j <= 30 ; j++) {
            cache[i][j] = -1;
        }
    }
	// 입력 및 실행 
	cin >> test;
	for(int i = 0; i < test; i++){
		cin >> n >> m;
		answer.push_back(nCr(m,n));
	}
	
	// 출력 
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';
} 
