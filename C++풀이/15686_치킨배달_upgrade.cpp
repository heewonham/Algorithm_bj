#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int n, m, ans = 9999;
vector<pii> chick;
vector<pii> house;
vector<pii> list; // dfs���� ����� ����Ʈ 

bool visit[13]; //�湮 üũ  
int Min(int A, int B) { if (A < B) return A; return B; }

int Cal()
{
    int Sum = 0;
    //���� ���ؼ� �Ǵ� 
    for (int i = 0; i < house.size(); i++)
    {
        int x = house[i].first;
        int y = house[i].second;
        int d = 99999999;

        for (int j = 0; j < list.size(); j++)
        {
            int xx = list[j].first;
            int yy = list[j].second;
            int Dist = abs(xx - x) + abs(yy - y); //��� 

            d = Min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}

void promising(int idx,int cnt){

    // ��������
    if(cnt == m){
        ans = Min(ans, Cal());
        return;
    }

    //�ᱹ ġŲ�� ������ŭ ������ȴ�. 
    for(int i =idx; i<chick.size(); i++)
    {
        if(visit[i] == true) continue;  //�湮���� Ȯ��
        visit[i] = true;
        list.push_back(chick[i]);
        promising(i, cnt+1);
        visit[i] = false; // backTrackin�ؾ��ϹǷ�..
        list.pop_back(); //�߰��ߴ��͵� ���� �������ش�.. 
     } 
}
int main(){

    int tmp;
    cin >> n >> m;

    //��ǲ �ޱ� --> good 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> tmp;
            if(tmp == 1)
                house.push_back(pii(i,j));
            else if(tmp == 2)
                chick.push_back(pii(i,j));
        }
    }

    // ����
    promising(0,0);

    // ���
    cout << ans; 
} 
