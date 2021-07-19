#include <iostream>
#include <string.h>
using namespace std;
typedef pair<int,int> pii;

int mat[1001][1001];
char ans[1001];
int main(){
	
	char a[1001], b[1001];
	cin >> a;
	cin >> b;
	
	// LCS
	for(int i = 0; i < strlen(a); i++){
		for(int j = 0; j < strlen(b); j++){
			if(a[i] == b[j])
				mat[i+1][j+1] = mat[i][j]+1;
			else
				mat[i+1][j+1] = max(mat[i][j+1],mat[i+1][j]);	
		}
	}
	
	// 찾기
	int idx = mat[strlen(a)][strlen(b)] - 1;
	pii pos = pii(strlen(a),strlen(b));
	while(idx >= 0){
		pii tmp;
		if(mat[pos.first-1][pos.second] > mat[pos.first][pos.second-1])
			tmp = pii(pos.first-1,pos.second);
		else
			tmp = pii(pos.first,pos.second-1);

		//
		if(mat[tmp.first][tmp.second] <= mat[pos.first-1][pos.second-1] && idx == mat[pos.first-1][pos.second-1]){
			ans[idx--] = b[pos.second-1];
			tmp = pii(pos.first-1,pos.second-1);
		}
		
		pos = tmp;
	}	
	
	// 디버그 출력 
	for(int i = 1; i < strlen(a)+1; i++){
		for(int j = 1; j < strlen(b)+1; j++){
			cout << mat[i][j]; 
		}
		cout << '\n';

	}
	
	// 최종출력 
	cout << mat[strlen(a)][strlen(b)] << '\n';
	if(mat[strlen(a)][strlen(b)] == 0) return 0;
	for(int i = 0; i < strlen(ans); i++){
		cout << ans[i]; 
	}
}
