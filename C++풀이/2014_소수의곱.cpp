#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
typedef long long LL;

int k, n; 
priority_queue<int, vector<int>, greater<int>> pq;
vector<LL> prime; 
int main(){
	// 우선순위 큐를 만들고, 처음 수를 그대로 넣음
	// 하나씩 빼고 카운팅 그리고 처음 받은 수 곱하고 집어넣음 
	// 단, 중복불가므로 뺄 때 그전이랑 수가 같다면 계속 뺌
	// 정답이 2^31보다 작으므로 제한을 둠 
	cin >> k >> n;
	for(int i=0; i < k; i++){
		int tmp;
	 	cin >> tmp;
	 	prime.push_back(tmp);
	 	pq.push(tmp);
	}
	
	int cnt = 0;
	LL prev = 0;
	while(1){
		if(pq.top() == prev){
			pq.pop();
			continue;
		}
		prev = pq.top();
		pq.pop();
		cout << prev << endl; 
		cnt++;
		if(cnt == n) break;
		for(int i = 0; i < k; i++){
            if(prev*prime[i] > 2147483647) continue; // 2^31
			pq.push(prev*prime[i]);
		}
	}
	
	cout << prev;
}
