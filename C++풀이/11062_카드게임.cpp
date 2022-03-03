#include <iostream>
#include <vector>
using namespace std;

int test, n;
vector<int> answer;
vector<int> card;
int dp[1001][1001];
int dp_f(int l, int r, bool who){
	
	if(who && r-l == 1) return dp[l][r] = max(card[r],card[l]);		// �ΰ� ������ �� 
	if(who && l == r) return dp[l][r] = card[l]; 					// �ϳ��� ������ �ٿ첨 
	if(dp[l][r]) return dp[l][r];									// ���� �� ������ 
	
	if(who)
		return dp[l][r] = max(card[l]+dp_f(l+1,r,!who), card[r]+dp_f(l,r-1,!who));
	else
		return dp[l][r] = min(dp_f(l+1,r,!who), dp_f(l,r-1,!who));
}
int main(){
	
	cin >> test;
	
	while(test--){
		
		card.clear();
		// �ʱ�ȭ 
		for(int i = 0; i < 1001; i++)
			for(int j = 0; j < 1001; j++)
				dp[i][j] = 0;
		
		// 1. �Է� 
		cin >> n;
		for(int j = 0; j < n; j++){
			int num;
			cin >> num;
			card.push_back(num);
		}
		
		// dp����
		bool who = true;
		answer.push_back(dp_f(0,n-1,who));
		
		for(int i = 0; i < n+1; i++){
			for(int j = 0; j < n+1; j++){
				cout << dp[i][j] << " ";
			}	
			cout << '\n';
		}

	}
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << '\n';
	}
}
