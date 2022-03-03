#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int path[20001] = {0};
void dik(int s, vector<pii> mat[])
{
	
	priority_queue<pii> p;
	p.push(pii(0,s));
	while(!p.empty()){
		pii tmp = p.top();
		int w = tmp.first;
		int v = tmp.second;
		p.pop();
		if(path[v] != -1) continue;
		path[v] = -w;
		for(int i = 0; i < mat[v].size(); i++){
			int nextv = mat[v][i].first;
			int nextw = -mat[v][i].second+w;
			p.push(pii(nextw,nextv));
		}
	}
}
int main(){
	
	int vc, ec, s;
	
	// 입력 
	cin >> vc >> ec >> s;
	vector<pii> mat[vc+1];
	for(int i = 0; i < ec; i++){
		int a, b, c;
		cin >> a >> b >> c;
		mat[a].push_back(pii(b,c));
	}
	
	// 초기화 
	for(int i = 0; i <= vc; i++)
		path[i] = -1;
		
	// 다익스트라
	dik(s,mat);
	
	// 출력 
	for(int i = 1; i <= vc; i++){
		if(path[i] == -1)
			cout << "INF" << '\n';
		else
			cout << path[i] << '\n';
	}
	 
}
