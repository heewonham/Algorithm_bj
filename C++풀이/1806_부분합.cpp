#include <iostream>
#include <vector>
/* ���� ���� �ƴ϶� �̻��� �Ǵ� ���� ���� ª�� ��... */
using namespace std;
typedef long long LL;

LL list[100000];
LL n, s, min_c = 100001;
int main(){
	
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> list[i];
	}
	
	// �������� Ȱ��
	LL start = 0, end = 0;
	LL st, ed;
	LL sum = 0;
	int flag = 0;
	while(flag == 0){
		flag = 1;
		while(end < n && sum < s){
			sum += list[end++];
			flag = 0;
		}
		if(sum >= s){
			if(min_c > end - start)
				min_c = end - start;
			sum -= list[start++];
			flag = 0;
		}
	}
	
	if(min_c == 100001)
		cout << 0;
	else
		cout << min_c;
}
