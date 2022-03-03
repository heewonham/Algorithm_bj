#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    long long answer = 0;
    long long start, end, mid;
    int sz = times.size();
    
    // ����
    sort(times.begin(), times.end());
    
    // �ּ��� �ð��� �־��� �ð�
    // times�� n ��� int�̱� ������ �Ѱ��� ����ȯ�� ���ؼ� long long�� �� �� �ֵ��� �Ѵ�.
    // ���� �����ɸ��� �ɻ��ڰ� ��� ���� ������� �� - �־�
    end = (long long)times[sz-1] * n; 
    start = 1;
    
    // ����
    while(start <= end){
        
        mid = (start + end) / 2;
        
        // �ش� �ð����� ó���� �� �ִ� �� ��
        long long cnt = 0;   
        for(int time : times)
            cnt += (mid / time);
        
       // ���� ������ ����
        if(cnt >= n){
            answer = mid;
            end = mid - 1;
        } 
        else start = mid + 1;
    }
    
    return answer;
}
