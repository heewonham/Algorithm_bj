#include <iostream>

using namespace std;

int n,m;
int A[10000];
int answer = 0;

int main(){
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	/* 완전탐색 비슷하게
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = i; j < n; j++){
			sum += A[j];
			if(sum == m){
				answer++;
				break;
			}
			else if(sum > m)
				break;
		}
	}*/
	// 투포인터 방식
	int s = 0, e = 0, sum = 0;
    for (s = 0 ; s < n ; s++) {
        for ( ; e < n ; e++) {
            if (sum >= m) {
                break;
            }
  		    sum += A[e];
    	}
        if (sum == m) {
        	answer++;
        }
        sum -= A[s];
    }        
	 
	cout << answer;
} 
