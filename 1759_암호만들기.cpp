/*
	알파벤 증가순 배열
	최소 한개의 모음과 최소 두개의 자음
	알파벳은 중복되어 제공되지 않는다. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
vector<char> alpa;
bool chk[16];
char ans[16];
void bfs(int idx, int ja, int mo){
	
	// 개수가 모자람 
	int cnt = ja + mo;
	if(l - cnt > c-idx) return;
	if(cnt == l && ja >= 2 && mo >= 1){
		for(int i = 0; i < c; i++){
			if(chk[i]){
				cout << alpa[i];
			}
		}
		cout << '\n';
	}
	
	for(int i = idx; i < c; i++){
		chk[i] = true;
		if(alpa[i] == 'a' || alpa[i] == 'e' || alpa[i] == 'i' ||
		alpa[i] == 'o'||alpa[i] == 'u')
			bfs(i+1,ja,mo+1);
		else
			bfs(i+1,ja+1,mo);
		chk[i] = false;
	}
}
int main(){

	cin >> l >> c;
	for(int i = 0; i < c; i++)
	{
		char a;
		cin >> a;
		alpa.push_back(a);
	}
	sort(alpa.begin(),alpa.end());
	
	bfs(0,0,0);
} 
