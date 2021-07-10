#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

char vill[50][51]; 		// ���� ���� 
int height_v[50][50]; 	// ���� ��  
vector<int> hi;			// ������ ����Ʈ 
pii post;				// ��ü���� ��ġ 
int n, house_c = 0;		// ���� ���� 

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};  
	
bool is_ok(int low, int high)
{
	
	queue<pii> list;
	bool visited[50][50]= {false, };
	int cnt = 0;
	
	if(height_v[post.first][post.second] < low || height_v[post.first][post.second] > high) return false;
	list.push(pii(post.first,post.second));
	visited[post.first][post.second] = true;
	
	while(!list.empty()){
		
		int x = list.front().first;
		int y = list.front().second;
		list.pop();
		
		// �� �� �� �� �밢�� �̵� 
		for(int i = 0; i < 8; i++){
			
			// �����������? 
			int xx = x+dx[i];
			int yy = y+dy[i]; 
			if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			// �湮����
			if(visited[xx][yy]) continue;
			
			// �湮, �� ������ ��� - ť�� �ְ� �湮üũ, K�� ��� cnt++ 
			if(height_v[xx][yy] >= low && height_v[xx][yy] <= high){
				visited[xx][yy] = true;
				list.push(pii(xx,yy));
				if(vill[xx][yy] == 'K')
					cnt++;
			}
		}
		// ��� ���� �湮���� ��� 
		if(cnt >= house_c) return true;
	}
	
	return false; 	
} 	
	
int main(){
	
	cin >> n;
	
	// ���� ���� �Է� 
	for(int i = 0; i < n; i++){
		cin >> vill[i];
		// �������� ��ü�ο� house�� ��ġ��ǥ ����
		for(int j = 0; j < n; j++){
			if(vill[i][j] == 'P'){
				post.first = i;
				post.second = j;
			}
			if(vill[i][j] == 'K'){
				house_c++;
			}			
		}
	}
	// ������ �� �Է�
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> height_v[i][j];
			hi.push_back(height_v[i][j]);
		}
	}
	
	// ����
		// 1. �������� ~ ���� ū ���̿��� �̵��ϸ� �̺�Ž��
	// ��� low�� top�� ���� ���ΰ� ??? 
	// 		�켱 ���� ó������ ������ �����ϰ� ����
	//	 low ~ top Ž���� ��� ���� Ž�� ������ ��� - low ��
	//	 low ~ top Ž���� �Ұ����� ��� - top�� �ٿ�
	sort(hi.begin(), hi.end());
	int answer = hi[hi.size()-1] - hi[0];

	/*int low = 0, high = 0;
	while(high < hi.size() && !is_ok(hi[low],hi[high])){
		while(hi[high] == hi[high+1])
			high++;
		high++;
	}
	cout << "high : "<< hi[high] << endl;
	while(low < hi.size() && is_ok(hi[low],hi[high]) && low <= high){
		int an = hi[high] - hi[low];
		cout << "low : " << hi[low] << endl;
		cout << "an : "<< an << endl;
		if(answer > an)
			answer = an;
		low++;
	}*/
	for (int low=0, high=0; low < hi.size() && high < hi.size(); ){
        if (low > high) break;
        if (is_ok(hi[low], hi[high])){
            int diff = hi[high] - hi[low];
            if (diff < answer) answer = diff;
            low++;
        }
        else high++;
    }
	// ���� ���� �Ƿε� ��� : low-1, high-1 
		// ���� high - low�� �� ���� �ְ� �ѵ��� ��� ��� - �ְ��ѵ��� ��� 

	cout << answer; 

}
