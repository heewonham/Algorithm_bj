#include <iostream>
using namespace std;
 
int n,k;
int child(int n, int k){
	int num = n;
	int ans = 1;
	for(int i = k; i > 0; i--){
		ans *= num;
		num--;
	}
	return ans;
}
int parent(int n, int k){
	int ans = 1;
	for(int i = 1; i <= k; i++){
		ans *= i;
	}
	return ans;
}
int main(){
	
	cin >> n >> k;
	int p = child(n,k);
	int q = parent(n,k);
	
	cout << p/q;
}
