#include <iostream>
#include <vector> 
using namespace std;
typedef pair<int,int> pii;

int n, k;
vector<pii> bag;
int mat[101][100001];
int main(){
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int w, v;
		cin >> w >> v;
		bag.push_back(pii(w,v));	
	}
	
	for(int i = 0; i < bag.size(); i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(bag[i].first > j)
				mat[i+1][j] = mat[i][j];
			else
				mat[i+1][j] = max(mat[i][j], mat[i][j-bag[i].first]+bag[i].second);		
		}
	}
	
	cout << mat[n][k];
}
