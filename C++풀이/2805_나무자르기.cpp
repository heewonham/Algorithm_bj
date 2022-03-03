#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef long long LL;

int n, m;
LL answer;
LL tree[1000000];

bool cut_ok(LL h){
	LL sum = 0;
	for(int i =0; i < n; i++){
		if(tree[i] > h)
			sum += (tree[i] - h) ;
		if(sum >= m) return true;
		// ���̻� �� �͵� ����. 
	}
	// ���� ���� ���� �̹� �Ұ���
	return false; 
}
int main(){
	
	cin >> n >> m;
	LL top = -1;
	for(int i =0; i < n; i ++){
		cin >> tree[i];
		if(top < tree[i])
			top = tree[i];
	}
	
	// ���Ѽ�, ���Ѽ� , �߰�
	LL bottom = 0, mid;
	while(bottom <= top){
		mid = (bottom + top) / 2;
		if(cut_ok(mid)){
			if(answer < mid) answer = mid;
			bottom = mid + 1;
		}
		else{
			top = mid -1;
		}
	} 
	// ���̸� �����ذ��鼭 ������ �߶󺸰� 
	// ������ �����ϴ� ���� ū ���̸� ã�ƺ���.
	cout << answer;	
}
/*vector<int> tree(1000000);
//int height = 0;

int main(){
	int max = -1;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> tree[i];
		if(max < tree[i])
			max = tree[i];
	}
	sort(tree.begin(), *(tree+n));
	for(int i = 0; i < n; i++){
		cout >> tree[i];
	}
	/*int tr_num = 0;
	int sum = 0;
	int next = 0;
	for(int i = max; i >= 0; i--){
		while()
	}
	
	cout << height;	
}*/
