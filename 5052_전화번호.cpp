#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Number{
public:
	Number(): end(false), child() {}
	
	bool Insert(string str){
		Number* cur = this;
		for(char ch : str){
			if(cur->child[ch-'0'] == nullptr){
				cur->child[ch-'0'] = new Number();
			}
			cur = cur->child[ch-'0'];
			if(cur->end == true) {
				return false;
			}
			printf("%c ",ch);
		}
		cur->end = true;
		return true;
	}

private:
	bool end;
	Number* child[10];
};
int main(){
	int test;
	scanf("%d", &test);

	while(test--){
		vector<string> str;
		Number phone;
		int n;
		
		scanf("%d", &n);
		// input
		for(int i = 0; i < n; i++){
			string num;
			cin >> num;
			str.push_back(num);
		}
		
		sort(str.begin(), str.end());

		bool flag = true;
		for (int i = 0; i < n; i++){
			if(!phone.Insert(str[i])){
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}
	}
}
