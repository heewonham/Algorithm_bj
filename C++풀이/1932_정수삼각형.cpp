#include <iostream>
using namespace std;

int n;
int mat[501][501];
int main(){
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			int num;
			cin >> mat[i][j];
		}
	}	
	
	for(int i = n-1; i > 0; i--){
		for(int j = 1; j <= i; j++){
			mat[i][j] = max(mat[i+1][j]+mat[i][j], mat[i][j]+mat[i+1][j+1]);
		}
	}
	cout << mat[1][1];
}
