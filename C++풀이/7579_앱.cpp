#include <iostream>
#include <vector> 
using namespace std;
/* 
	�޸𸮴� �ִ븦 ���ϸ鼭, �ð��� �ּ� ���ϴ� ����  
*/
int n, m, ans = 10001;
int dp[101][10001];
int main(){
	
	cin >> n >> m;
	vector<int> byte(n);
	vector<int> cost(n);
	
	// 1. �Է� 
	for(int i = 0; i < n; i++) cin >> byte[i];
	for(int i = 0; i < n; i++) cin >> cost[i];


	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= 10000; j++)
		{
			if(cost[i] > j)
				dp[i+1][j] = dp[i][j];
			else
				dp[i+1][j] = max(dp[i][j], dp[i][j-cost[i]]+byte[i]);
				
			if(dp[i+1][j] >= m) 
				ans = min(ans,j); 	
		}
	}

	cout << ans;
}
