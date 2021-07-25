#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char word[10][9];
vector<int> alpa(26);  // A´Â 65 
int compare(int a, int b){
	return a > b;
}
int main(){
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> word[i];
		for(int k = strlen(word[i])-1, j = 0; j < strlen(word[i]); j++, k--){
			alpa[word[i][k]-65] += pow(10,j);
		}
	}
	sort(alpa.begin(),alpa.end(), compare);
	
	int sum = 0; 
	for(int i = 0, j = 9; i < 26 && j > 0; i++, j--){
		if(alpa[i] == 0) break;
		sum += alpa[i] * j;
	}
			
	cout << sum;
}
