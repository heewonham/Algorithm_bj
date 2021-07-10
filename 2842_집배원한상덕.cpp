#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

char vill[50][51]; 		// 마을 지도 
int height_v[50][50]; 	// 마을 고도  
vector<int> hi;			// 고도들의 리스트 
pii post;				// 우체국의 위치 
int n, house_c = 0;		// 집의 개수 

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
		
		// 상 하 좌 우 대각선 이동 
		for(int i = 0; i < 8; i++){
			
			// 정상범위인지? 
			int xx = x+dx[i];
			int yy = y+dy[i]; 
			if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
			// 방문여부
			if(visited[xx][yy]) continue;
			
			// 방문, 고도 정상인 경우 - 큐에 넣고 방문체크, K일 경우 cnt++ 
			if(height_v[xx][yy] >= low && height_v[xx][yy] <= high){
				visited[xx][yy] = true;
				list.push(pii(xx,yy));
				if(vill[xx][yy] == 'K')
					cnt++;
			}
		}
		// 모든 집을 방문했을 경우 
		if(cnt >= house_c) return true;
	}
	
	return false; 	
} 	
	
int main(){
	
	cin >> n;
	
	// 마을 지도 입력 
	for(int i = 0; i < n; i++){
		cin >> vill[i];
		// 마을내의 우체부와 house의 위치좌표 저장
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
	// 마을의 고도 입력
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> height_v[i][j];
			hi.push_back(height_v[i][j]);
		}
	}
	
	// 실행
		// 1. 가장작은 ~ 가장 큰 사이에서 이동하며 이분탐색
	// 어떻게 low와 top을 나눌 것인가 ??? 
	// 		우선 고도를 처음부터 끝까지 정렬하고 진행
	//	 low ~ top 탐색이 모든 집이 탐색 가능할 경우 - low 업
	//	 low ~ top 탐색이 불가능할 경우 - top을 다운
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
	// 가장 작은 피로도 출력 : low-1, high-1 
		// 만약 high - low를 뺀 수가 최고 한도를 벗어날 경우 - 최고한도로 출력 

	cout << answer; 

}
