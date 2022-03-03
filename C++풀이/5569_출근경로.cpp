#include <iostream>
#define MAX 100000

using namespace std;
int w, h;				// w >(j) : h ^ (i)
int matx[105][105][2]; // ^ 0 : > 1

void dp(){
	
	for(int i = 2; i <= h; i++){
		for(int j = 2; j <= w; j++){
			matx[i][j][0] = (matx[i-1][j][0] + matx[i-1][j-1][1])%MAX;
			matx[i][j][1] = (matx[i][j-1][1] + matx[i-1][j-1][0])%MAX;
		}
	}
	
}
int main(){
	
	scanf("%d %d", &w, &h);
	
	// ÃÊ±âÈ­
	for(int i = 1; i <= w; i++)
		matx[1][i][1] = 1;
	for(int i = 1; i <= h; i++)
		matx[i][1][0] = 1;
	 
	dp();
	printf("%d", (matx[h][w][0]+matx[h][w][1])%MAX);
}
