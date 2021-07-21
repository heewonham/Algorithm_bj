#include <iostream>
using namespace std;

int n,h;
int hit[500001];
int main(){
	
	cin >> n >> h;
	for(int i = 1; i <= n; i++){
		int height;
		cin >> height;
		if(i % 2 == 0) // 짝수 : 석순, 위에서 아래로
		{
			hit[h-height+1] += 1; 
		}
		else // 홀수 : 종유석 , 아래서 위로 
		{
			hit[1] += 1;
			hit[height+1] -= 1;
		}
	}
	
	int ob_min = hit[1], num = 1;
	int sum = hit[1];
	for(int i = 2; i <= h; i++)
	{
		sum += hit[i];
		// 최소이면  
		if(sum < ob_min){
			ob_min = sum;
			num = 1;
		}
		// 같으면 num 증가
		else if(sum == ob_min){
			num++;
		}
	}
	
	cout << ob_min << " " << num;
}
