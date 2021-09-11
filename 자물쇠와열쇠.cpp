#include <string>
#include <vector>

using namespace std;
int ckey[4][20][20]; //회전된 key 저장
void rot_key(int idx, int size){

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            ckey[idx][j][size-1-i] = ckey[idx-1][i][j];
    
}
// 완전탐색
bool unlock(vector<vector<int>> matrix,int idx, int x, int y, int off, int cnt){
    
    // 이미 열쇠가 lock한 부분이 없는 경우 true 반환
    if(cnt == 0) return true;
    
    // 완전탐색
     int msz = matrix[0].size();
     for(int i = x; i <= x+off; i++){
         for(int j = y; j <= y+off; j++){
             // 자물쇠 부분에 맞는 키부분
             if(i >= off && j >= off && i < msz-off && j < msz-off){
                int tmp = matrix[i][j] + ckey[idx][i-x][j-y];
                if(tmp == 2) return false;
                if(matrix[i][j] == 0 && tmp == 1) {
                    if(--cnt == 0) return true;
                }
             }
         }
     }
    return false;
 }
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int M = lock[0].size(), offset = key[0].size()-1;
    int cnt = 0;                 // 자물쇠의 구멍수 
    
    int m_size = M + (offset*2); // 임시공간의 배열선언
    vector<vector<int>> matrix(m_size, vector<int>(m_size));
    
    // 미리 회전된 키를 저장한다
    for(int i = 0; i < 4; i++){
        if(i == 0) { // 움직이지 않은 처음 경우 그대로 복사
            for(int j = 0; j <= offset; j++)
                for(int k = 0; k <= offset; k++)
                    ckey[0][j][k] = key[j][k];
        }
        else rot_key(i, offset+1); 
    }

    // 임시의 매트리스에 자물쇠를 저장한다
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            matrix[i+offset][j+offset] = lock[i][j];
            if(lock[i][j] == 0) cnt++;
        }
    }

    // 본격 완전탐색 시작
     for(int i = 0; i < m_size-offset; i++){
         for(int j = 0; j < m_size-offset; j++){
             for(int k = 0; k < 4; k++){ // key 회전부분
                 if(unlock(matrix, k, i, j, offset, cnt)) return true;
             }
         }
     }
        
    return answer;
}
