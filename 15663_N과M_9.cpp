#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int n, m;
vector<int> num;
bool visited[8] = {false, };
int answer[8];
// 수열은 사전증가순으로 증가한다. 
// 우선 정렬 --> 
void dp(int r){
	if(r == m){
		for(int i = 0; i < m; i++){
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	if(r < 0 ) return;
	int prev_n = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i] && prev_n != num[i]) {
			visited[i] = true;
			answer[r] = num[i];
			prev_n = num[i];
			dp(r+1);
			visited[i] = false;
		}
	}
}
int main(){
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	
	sort(num.begin(),num.end());
	
	// 실행 및 출력
	dp(0);
}
