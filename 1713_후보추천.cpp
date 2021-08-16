#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct st{
	int num;
	int rate;
	int seq;
};
vector<st> players;
int chk(int s){
	
	for(int i = 0; i < players.size(); i++){
		if(players[i].num == s){
			players[i].rate++;
			return 1;
		}
	}
	
	return 0;
}
void update(st stu){
	
	int idx = 0; 
	for(int i = 1; i < players.size(); i++){
		if(players[idx].rate > players[i].rate)
			idx = i;
		else if(players[idx].rate == players[i].rate)
			idx = players[idx].seq > players[i].seq? i : idx;
	}

	players[idx].num = stu.num;
	players[idx].rate = 1;
	players[idx].seq = stu.seq;
	
}
bool compare(st a, st b){
	if(a.num < b.num) return true;
	return false;
}
int main(){
	
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= m; i++){
		struct st student = {0, 1, i};
		scanf("%d",&student.num);
		// 후보에 있는지 ?? 
		int c = chk(student.num); 
		
		if(!c){
			// 자리는 비어있는지?
			if(players.size() < n) players.push_back(student);
			else // 갱신 
				update(student);
		}
	}
		
	sort(players.begin(), players.end(), compare);
	for(int i = 0; i < players.size(); i++)
		printf("%d ",players[i].num);
}

