/*
	���ĺ� ������ �迭
	�ּ� �Ѱ��� ������ �ּ� �ΰ��� ����
	���ĺ��� �ߺ��Ǿ� �������� �ʴ´�. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
vector<char> alpa;
bool chk[16];
char ans[16];
void bfs(int idx, int ja, int mo){
	
	// ������ ���ڶ� 
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
