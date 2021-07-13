#include <iostream>
#include <vector>
using namespace std;

int n, m;
int p[1000001];
vector<int> answer;
int find(int a)
{
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}
void uni(int a, int b)
{
	int c = find(a), d = find(b);
	if(c < d) p[d] = c;
	else p[c] = d; 	
}
int main(){
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		p[i] = i;
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		
		if( a == 0){
			uni(b,c);	
		}
		else{
			if(find(b) != find(c))
				answer.push_back(0);
			else
				answer.push_back(1);
		}
 	}
 	
 	for(int i = 0; i < answer.size(); i++){
 		if(answer[i] == 1)
 			cout << "YES" << '\n';
 		else
 			cout << "NO" << '\n';
	 }
}
