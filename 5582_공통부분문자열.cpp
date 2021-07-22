#include <iostream>
#include <string.h>
using namespace std;

int mat[4001][4001];
int ans = 0;
int main(){
	char f[4001], s[4001];
	cin >> f;
	cin >> s;
	for(int i = 0; i < strlen(f); i++){
		for(int j = 0; j < strlen(s); j++){
			if(f[i] == s[j]){
				mat[i+1][j+1] = mat[i][j] + 1;
				ans = max(ans,mat[i+1][j+1]);
			}
				
			else
				mat[i+1][j+1] = 0; 
		}
	}
	cout << ans;
}
