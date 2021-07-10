#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n, m, ans = 9999;
vector<pii> chick;
vector<pii> house;
vector<pii> list; // dfs에서 사용할 리스트 

bool visit[13]; //방문 체크  
int Min(int A, int B) { if (A < B) return A; return B; }

int Cal()
{
    int Sum = 0;
    //집에 대해서 판단 
    for (int i = 0; i < house.size(); i++)
    {
        int x = house[i].first;
        int y = house[i].second;
        int d = 99999999;

        for (int j = 0; j < list.size(); j++)
        {
            int xx = list[j].first;
            int yy = list[j].second;
            int Dist = abs(xx - x) + abs(yy - y); //계산 

            d = Min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}

void promising(int idx,int cnt){

    // 종료조건
    if(cnt == m){
        ans = Min(ans, Cal());
        return;
    }

    //결국 치킨의 갯수만큼 돌리면된다. 
    for(int i =idx; i<chick.size(); i++)
    {
        if(visit[i] == true) continue;  //방문여부 확인
        visit[i] = true;
        list.push_back(chick[i]);
        promising(i, cnt+1);
        visit[i] = false; // backTrackin해야하므로..
        list.pop_back(); //추가했던것도 같이 제거해준다.. 
     } 
}
int main(){

    int tmp;
    cin >> n >> m;

    //인풋 받기 --> good 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tmp;
            if(tmp == 1)
                house.push_back(pii(i,j));
            else if(tmp == 2)
                chick.push_back(pii(i,j));
        }
    }

    // 진행
    promising(0,0);

    // 출력
    cout << ans; 
} 
