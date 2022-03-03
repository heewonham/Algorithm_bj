#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int n, k, cnt = 0;
int dp[205][205];
int light[205];
int DP(int s, int e){
	
	// 초과시 
	if (s > e || e > cnt) return 0;
	
	//이미 있으면 출력
	if(dp[s][e] > -1) return dp[s][e];
	
	// s와 e가 같으면
	if(s == e) return dp[s][e] = 0;
	 
	for(int i = s; i < e; i++){
		printf("start\n");
		int left = DP(s, i);
		int right = DP(i+1, e);
		
		printf("left = %d ~ %d : %d\n",s,i,left);
		printf("right = %d ~ %d : %d\n",i+1,e,right);
		 
		if(dp[s][e] == -1)
			dp[s][e] = left+right+(light[i-1] != light[e]);
		else
			dp[s][e] = min(dp[s][e], (left+right+(light[i-1] != light[e])));
		
		printf("dp = %d ~ %d : %d\n",s,e,dp[s][e]);
	}
	
	return dp[s][e];
}
int main(){
	
	// 1. 입력 
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int lgt;
		scanf("%d", &lgt);
		if(cnt == 0 || light[cnt-1] != lgt)
			light[cnt++] = lgt;		
	}

	// 2. 초기화
	for(int i = 1; i <= cnt; i++)
		memset(dp[i], -1, sizeof(int)*(cnt+1));

	// 3. dp + 출력 
	printf("%d", DP(1,cnt));
	
}
