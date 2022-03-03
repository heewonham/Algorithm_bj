#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
typedef long long LL;

int k, n; 
priority_queue<int, vector<int>, greater<int>> pq;
vector<LL> prime; 
int main(){
	// �켱���� ť�� �����, ó�� ���� �״�� ����
	// �ϳ��� ���� ī���� �׸��� ó�� ���� �� ���ϰ� ������� 
	// ��, �ߺ��Ұ��Ƿ� �� �� �����̶� ���� ���ٸ� ��� ��
	// ������ 2^31���� �����Ƿ� ������ �� 
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
