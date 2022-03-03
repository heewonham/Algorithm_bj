#include <iostream>
#define INF 1000000010
using namespace std;
int n,m,k;
 
char ans[201];
int cache[101][101] = {0, }; 
// a�� z�� ���� 
int dic(int a, int z)
{
	// a�� 0�̰ų� z�� 0�� ��� ���̻� ������ �Ұ� 
	if(a == 0 || z == 0 )
		return 1;
	
	// �̹� �湮�� ���  
	if(cache[a][z] != 0)
		return cache[a][z];
	
	// ����� �� ������ �����ϴ� �۾� 
	cache[a][z] = dic(a -1, z) + dic(a, z-1);
	// ���� ����� ����� ���� �ִ밪�� 10���� �ʰ��� ���
	// ���� 10�� �̻��� ������ �ʿ�� ����.
	if (cache[a][z] >= INF) {
    	cache[a][z] = INF;
    }
    return cache[a][z];
}

int main(){
	
	cin >> n >> m >> k;
	
	// ���� �� k�� �ʰ���  
	if(dic(n,m) < k){
		cout << -1;
		return 0;
	}
	
	// ��� : ����� �� �ȿ� �ִ� ��� Ž�� 
	int ac = n, zc = m; 
	for (int i = 0 ; i < n + m ; i++) {
    	if (ac > 0) {
            int tmp = dic(ac - 1, zc);
            if (tmp < k) {
                ans[i] = 'z';
                k -= tmp;
                zc--;
            }
            else {
                ans[i] = 'a';
                ac--;
            }
        }
        else ans[i] = 'z';
	}
	
	cout << ans;
}
