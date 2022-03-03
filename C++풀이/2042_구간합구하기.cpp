#include <iostream>
#define P (1<<20)
using namespace std;
typedef long long LL;

int N,M,K;
long long tree[P*2];
void update(LL n, LL v)
{
	n += P;
	tree[n] = v;
	n/=2;
	while(n)
	{
		// 조상 = 왼쪽자식 + 오른쪽자식
        tree[n] = tree[n*2] + tree[n*2+1];
        n/=2; // 그 윗 조상으로 옮김
	}
	
}
LL query(LL l, LL r)
{
	l += P, r += P;
    LL ret = 0;
    while(l<=r)
    {
        if (l%2==1) ret += tree[l++];
        if (r%2==0) ret += tree[r--];
        l/=2, r/=2;
    }
    return ret; 
}
int main(){
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		LL val;
		cin >> val;
		update(i,val);
	}
	
	for(LL i = 0; i < M+K; i++){
		LL a, b, c;
		cin >> a >> b >>c;
		if(a == 1)
		{
			update(b,c);
		}
		else if( a == 2)
		{
			cout << query(b,c) << '\n';
		}
	}
}
