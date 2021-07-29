#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pii;

int stoku[9][9];
bool ver[9][10], hor[9][10], mini[3][3][10];
vector<pii> ans;
bool backtracking(int idx){
	
	if (idx == ans.size()) return true;
	
	int x = ans[idx].first, y = ans[idx].second;
	for(int i = 1; i <= 9; i++){
		if(!hor[x][i] && !ver[y][i] && !mini[x/3][y/3][i]){
			stoku[x][y] = i;
			printf("%d %d = %d\n",x,y,i); 
			hor[x][i] = true;
			ver[y][i] = true;
			mini[x/3][y/3][i] = true;
			if(backtracking(idx+1)) return true;
			hor[x][i] = false;
			ver[y][i] = false;
			mini[x/3][y/3][i] = false;
		}
	}
	
	return false;
}
int main(){
	
	// 입력 
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j++){
			cin >> stoku[i][j];
			if(stoku[i][j] == 0){
				ans.push_back(pii(i,j));
			}
			else{
				hor[i][stoku[i][j]] = true;
				ver[j][stoku[i][j]] = true;
				if(i < 3){
					if(j < 3)
						mini[0][0][stoku[i][j]] = true;
					else if(j < 6)
						mini[0][1][stoku[i][j]] = true;
					else
						mini[0][2][stoku[i][j]] = true;
				}
				else if(i < 6){
					if(j < 3)
						mini[1][0][stoku[i][j]] = true;
					else if(j < 6)
						mini[1][1][stoku[i][j]] = true;
					else
						mini[1][2][stoku[i][j]] = true;
				}
				else{
					if(j < 3)
						mini[2][0][stoku[i][j]] = true;
					else if(j < 6)
						mini[2][1][stoku[i][j]] = true;
					else
						mini[2][2][stoku[i][j]] = true;
				}
			}
		}
	}
	
	// 백트래킹 
	backtracking(0);
	
	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j++){
			cout << stoku[i][j] << " ";
		}
		cout << '\n';
	}
}
