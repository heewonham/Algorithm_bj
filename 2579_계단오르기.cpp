#include <iostream>
#include <vector>
using namespace std;
 
int point[301][2];
vector<int> stair;
int n,ans;
int main(){
	
	int tmp;
	cin >> n;
	stair.push_back(0);
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		stair.push_back(p);
	}
	
	for(int i = 1; i <= n; i++){
		if(i < 2){
			point[i][0] = stair[i];
		}
		else{
			point[i][0] += (stair[i] + max(point[i-2][0], point[i-2][1]));
			point[i][1] += (stair[i] + point[i-1][0]);
		}
		cout << stair[i] << " : ";
		cout << point[i][0] << " " << point[i][1] <<endl;
	}
	
	ans = max(point[n][0], point[n][1]);

	cout << ans;
}
