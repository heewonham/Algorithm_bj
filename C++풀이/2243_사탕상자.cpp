/*
	������ �� - 1 ~ 1000000
	1�� ���ִ� ����, �������� ������ ����
	1���� 3�� ������ �� ������ ������ 4����
	 
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
		
	// �ڽĳ���� ���ʺ��� ���ų� ���� ��� 
	if(tree[node * 2 ] >= idx){
		tree[node] -= 1;
		return query(node *2, s, (s+e)/2, idx);
	}
	// �ƴ� ��� val�� ���� ���ʳ�常ŭ �����ϰ� �̵�
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
			// b��° ������ ���ְ� ���� �� ��� 
			scanf("%d", &b);
			printf("%lld\n", query(1,1,MAX,b));
		}
		else{
			// b��° ������ c����ŭ ���ϰų� �� 
			scanf("%d %d", &b, &c);
			if( c < 0 ){
				// ������ ��� ���� 
				update(1,1,MAX,b,c);
			}
			else{
				// ����� ��� �ش� �� ������ 
				update(1,1,MAX,b,c);
			}
		}
	}
} 
