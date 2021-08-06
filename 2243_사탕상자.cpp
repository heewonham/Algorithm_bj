/*
	사탕의 맛 - 1 ~ 1000000
	1번 맛있는 사탕, 마지막이 맛없는 사탕
	1번이 3개 있으면 그 다음은 순서로 4등임
	 
*/
#include <iostream>
#define DIV 1 << 21
#define MAX 1000005

typedef long long LL;
using namespace std;
int n;
LL tree[DIV]; 
LL update(int node, int s, int e, int idx, int val){
	
	if(idx < s || e < idx ) return 0;
	if(s == e) return tree[node] += val;
	else{
		update(node * 2, s, (s+e)/2, idx, val);
		update(node * 2+1, (s+e)/2+1, e, idx, val);
		return tree[node] = tree[node*2]+tree[node*2+1];
	}
	
}
LL query(int node, int s, int e, int idx){
	
	if(s == e){
		tree[node] -= 1;
		return s;
	}
		
	// 자식노드중 왼쪽보다 같거나 작을 경우 
	if(tree[node * 2 ] >= idx){
		tree[node] -= 1;
		return query(node *2, s, (s+e)/2, idx);
	}
	// 아닐 경우 val의 값을 왼쪽노드만큼 삭제하고 이동
	else{
		tree[node] -= 1;
		return query(node * 2 + 1, (s+e)/2 + 1, e, idx-tree[node*2]);
	}

}
int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b, c;
		scanf("%d ", &a);
		if(a == 1){
			// b번째 사탕을 빼주고 사탕 맛 출력 
			scanf("%d", &b);
			printf("%lld\n", query(1,1,MAX,b));
		}
		else{
			// b번째 사탕을 c개만큼 더하거나 뺌 
			scanf("%d %d", &b, &c);
			if( c < 0 ){
				// 음수일 경우 빼줌 
				update(1,1,MAX,b,c);
			}
			else{
				// 양수일 경우 해당 맛 더해줌 
				update(1,1,MAX,b,c);
			}
		}
	}
} 
