#include <iostream>

int n, ans;
int chess[14][14];
using namespace std;

// line : 0 ~ n - 1
void recur(int line) {
    // 종료조건
    if (line == n) {
        ans++;
        return;
    }
    // line어딘가에다가 queen을 놓아본다
    for (int i = 0 ; i < n ; i++) {
        if (chess[line][i] != -1) continue;
        chess[line][i] = line;
        // line에 놓았으니까 상/하/좌/우/대각선에는 queen을 놓지 못하게 처리한다 
        // 좌/우 
        for (int x = 0 ; x < n ; x++) {
            if (chess[line][x] == -1) {
                chess[line][x] = line;
            }
        }
        // 하
        for (int y = line ; y < n ; y++) {
            if (chess[y][i] == -1) {
                chess[y][i] = line;
            }
        }       
        // 대각선
        for (int y = line, x = i ; y < n && 0 <= x ; y++, x--) {
            if (chess[y][x] == -1) {
                chess[y][x] = line;
            }
        }
        for (int y = line, x = i ; y < n && x < n ; y++, x++) {
            if (chess[y][x] == -1) {
                chess[y][x] = line;
            }
        }

        // 다음 줄 queen을 놓아본다
        recur(line + 1);

        // 지금 queen이 처리한 흔적을 지운다.
        for (int x = 0 ; x < n ; x++) {
            if (chess[line][x] == line) {
                chess[line][x] = -1;
            }
        }
        // 하
        for (int y = line ; y < n ; y++) {
            if (chess[y][i] == line) {
                chess[y][i] = -1;
            }
        }       
        // 대각선
        for (int y = line, x = i ; y < n && 0 <= x ; y++, x--) {
            if (chess[y][x] == line) {
                chess[y][x] = -1;
            }
        }
        for (int y = line, x = i ; y < n && x < n ; y++, x++) {
            if (chess[y][x] == line) {
                chess[y][x] = -1;
            }
        }
    }
}
int main(){
	
	// array fill
    for (int i = 0 ; i < 14 ; i++) {
        for (int j = 0 ; j < 14 ; j++) {
            chess[i][j] = -1;
        }
    }
    
	cin >> n;
	recur(0);
	
	cout << ans;
}
