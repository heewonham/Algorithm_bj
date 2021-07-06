#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int max_n = 0;
char word[55][55];
bool visit[26] = {false, };
vector<char> alpa;
int alphabet[26];

void promising(int idx, int cnt);
int chk();

int main(){
    int i, j;
    int count = 0;
    char wd[27] = {'\0',};
    cin >> n >> k;

    // 초기화 : a n t i c
    visit['a'-97] = true;
    visit['n'-97] = true;
    visit['t'-97] = true;
    visit['i'-97] = true;
    visit['c'-97] = true;

    alphabet['a'-97] = 1;
    alphabet['n'-97] = 1;
    alphabet['t'-97] = 1;
    alphabet['i'-97] = 1;
    alphabet['c'-97] = 1;

    for(i = 0; i < n; i++){
        cin >> word[i];
        for(j = 4; j < strlen(word[i])-4; j++){
            if(!visit[(int)word[i][j]-97]){
                visit[(int)word[i][j]-97] = true;
                alpa.push_back(word[i][j]);
            }
        }
    }

    if(k < 5){ // 5개보다 적을 경우
        cout << 0;
        return 0;
    }
    else{ // 5개 이거나 이상인 경우
        if((k-5) >= alpa.size()){
            cout << n;
            return 0;
        }
        promising(0, 0);
    }

    cout << max_n;
}
void promising(int idx, int cnt){

    if(cnt == (k-5)){
        // 개수 확인
        int count = chk();

        if(max_n < count)
            max_n = count;
            return;

    }
	// 가지치기
	if(alpa.size()-idx + cnt < k-5) return; 
	
	if(idx < alpa.size()){
		int a = alpa[idx]-97;

        if(alphabet[a]!=1)
        {
            alphabet[a] = 1;
            promising(idx+1, cnt+1);
            alphabet[a] = 0;
            promising(idx+1, cnt);
        }

	}
}

int chk(){
    int i, j, k;
    int cnt = 0, flag = 0;

    for(i = 0; i < n; i++){ // 단어 개수 
        flag = 0;
    //조합한 문자에 대하여..... 
        for(j = 0; j < strlen(word[i]); j++){            
            if(alphabet[word[i][j]-'a'] == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cnt++;
    }
    return cnt;
}
