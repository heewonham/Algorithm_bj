#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0, sz = scoville.size();
    int s1, s2, s3;
    
    priority_queue<int> q;
    for(int i : scoville) q.push(-i);
    
    while(-q.top() < K && q.size() > 1){
        s1 = -q.top(); q.pop();
        s2 = -q.top(); q.pop();
        q.push(-(s1 + (s2 * 2)));
        answer++;
    }
    
    if(-q.top() < K) answer = -1;
    return answer;
}
