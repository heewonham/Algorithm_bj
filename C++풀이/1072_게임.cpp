#include <iostream>
using namespace std;
/*
	������ : 
	���� ������ ��� �� ����. 
		1. x,y�� ���� ��� - 100����
		2. x,y�� 99������ ��� 
	
	�ϳ��� �ø��� --- Ÿ�Ӿƿ� 
	���� �� �ִ� ��� ???
		�̺�Ž�� ---> ��ü������ ��� ������ ������?
		1. ó�� �־��� x�� �ִ밪���� �����ϰų�
		2. 2x , y+x�� ��� �������� ������? 
		 
*/
long x, y, z;
int main(){
	
	cin >> x >> y;
	
	z = y * 100 / x;
	
	// ���� ó��
	if( x == y || z == 99 ){
		cout << -1;
		return 0;
	} 
	
	// ����
	long bottom = 1, top = 1000000000, mid;
	long ans = 1000000000;
	// topã��
	/*while(((y + top) * 100 / (x + top)) <= z){
		top *= 2;
	}*/
	while(bottom <= top){
		mid = (bottom + top) / 2;
		// ����  
		long nextz = (y + mid) * 100 / (x + mid);
		if(z < nextz){
			if(mid < ans) {
				ans = mid;
			}
			top = mid -1;
		}
		else{
			bottom = mid + 1;
		} 
	} 
	
	cout << ans;
}
