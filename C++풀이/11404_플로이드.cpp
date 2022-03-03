#include <iostream>
#define MAX 100000000
using namespace std;

int n, m;
int city[101][101] = {0, };
int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			city[i][j] = MAX; 
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(city[a][b] > c)
			city[a][b] = c;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(j == k) city[j][k] = 0;
				else
					city[j][k] = min(city[j][k],city[j][i]+city[i][k]);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(city[i][j] == MAX)
				cout << 0 << " ";
			else
				cout << city[i][j] << " ";
		}
		cout << '\n';
	}
}
