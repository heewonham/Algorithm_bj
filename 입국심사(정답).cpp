#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long answer = 0;
    long long start, end, mid;
    int sz = times.size();
    
    // 정렬
    sort(times.begin(), times.end());
    
    // 최선의 시간과 최악의 시간
    // times와 n 모두 int이기 때문에 한개는 형변환을 통해서 long long이 될 수 있도록 한다.
    // 가장 오래걸리는 심사자가 모든 고객을 담당했을 때 - 최악
    end = (long long)times[sz-1] * n; 
    start = 1;
    
    // 수행
    while(start <= end){
        
        mid = (start + end) / 2;
        
        // 해당 시간내에 처리할 수 있는 고객 수
        long long cnt = 0;   
        for(int time : times)
            cnt += (mid / time);
        
       // 범위 좁히는 과정
        if(cnt >= n){
            answer = mid;
            end = mid - 1;
        } 
        else start = mid + 1;
    }
    
    return answer;
}
