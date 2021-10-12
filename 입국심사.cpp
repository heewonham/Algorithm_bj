#include <string>
#include <vector>
#define PRO 100001
#define DIV (1 << 18)

using namespace std;
typedef pair<int,long long> pii;

vector<vector<int>> v;
pii tree[DIV+5];
int im[PRO];
pii update(int node, int s, int e, int idx, int val){
    if(s == e){
        tree[node].second += val;
        return tree[node];
    }
    
    if(s <= idx && (s+e)/2 >= idx){
        pii left = update(node*2, s, (s+e)/2, idx, val);
        return tree[node] = left.second < tree[node*2+1].second ? left : tree[node*2+1];
    }
    else{
        pii right = update(node*2+1, (s+e)/2+1, e, idx, val);
        return tree[node] = right.second < tree[node*2].second ? right : tree[node*2];
    }
    
}
pii init(int node, int s, int e){
    if(s == e){
        tree[node].first = s;
        tree[node].second = im[s];
        //tree[node].second = v[0][s-1];
        return tree[node];
    }
    
    pii left = init(node*2, s, (s+e)/2);
    pii right = init(node*2+1,(s+e)/2+1,e);
    return tree[node] = left.second < right.second ? left : right;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    int idx = (DIV/2), sz = times.size();
    
    // √ ±‚»≠
    for(int i = 0; i < sz; i++) im[i+1] = times[i];
    //v.push_back(times);
    init(1,1,sz);

    for(int i = 0 ; i < n; i++){
        answer = tree[1].second;
        long long val = times[tree[1].first-1];
        update(1,1,sz,tree[1].first,val);
    }
    
    return answer;
}
