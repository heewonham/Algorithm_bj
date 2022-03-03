#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<int> ans;
int main(){
	
	cin >> n;
	priority_queue<int> max_q;
	priority_queue<int, vector<int> ,greater<int>> min_q;
	for(int i = 1; i <= n; i++){
		int tmp;
		cin >> tmp;
		if(i % 2 == 0) // Â¦¼ö
			min_q.push(tmp);
		else // È¦¼ö
			max_q.push(tmp);
			
		if(!min_q.empty() && max_q.top() > min_q.top()){
			int a = max_q.top();
			int b = min_q.top();
			max_q.pop(), min_q.pop();
			max_q.push(b);
			min_q.push(a);
		}
		
		tmp = max_q.top();
		ans.push_back(tmp);
	}
	
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}
