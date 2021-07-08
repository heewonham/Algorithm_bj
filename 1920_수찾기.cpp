#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> narray;
vector<int> ans;

int n, m;
int binary_search(int key);

int main(){
	
	int i, tmp;
	
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> tmp;
		narray.push_back(tmp);
	}
	sort(narray.begin(),narray.end());

	cin >> m; 
	for(i =0; i < m; i++){
		cin >> tmp;
		ans.push_back(tmp);
	}
	
	for(i = 0; i < m; i++){
		cout << binary_search(ans[i]) << '\n';
	}
} 
int binary_search(int key){
	int left, right, mid;
	left = 0;
	right = n-1;
	while(left <= right){
		mid = (left + right) / 2;
		if(narray[mid] == key) return 1;
		else if(key < narray[mid])
			right = mid-1;
		else
			left = mid+1;
	}
	return 0;
}
