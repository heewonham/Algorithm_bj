#include <string>
#include <vector>
#include <queue>
using namespace std;
struct st{
    int sum;
    int idx;
};
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<st> q;
    q.push(st{numbers[0],1});
    q.push(st{-numbers[0],1});
    
    while(!q.empty()){
        st n = q.front(); 
        q.pop();
        
        if(n.idx == numbers.size()){
            if(n.sum == target) answer++;
            continue;
        }
        q.push(st{n.sum+numbers[n.idx], n.idx+1});
        q.push(st{n.sum-numbers[n.idx], n.idx+1});
    }
    
    return answer;
}
