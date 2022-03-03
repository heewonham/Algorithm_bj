#include <string>
#include <vector>

using namespace std;
int ckey[4][20][20]; //ȸ���� key ����
void rot_key(int idx, int size){

    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            ckey[idx][j][size-1-i] = ckey[idx-1][i][j];
    
}
// ����Ž��
bool unlock(vector<vector<int>> matrix,int idx, int x, int y, int off, int cnt){
    
    // �̹� ���谡 lock�� �κ��� ���� ��� true ��ȯ
    if(cnt == 0) return true;
    
    // ����Ž��
     int msz = matrix[0].size();
     for(int i = x; i <= x+off; i++){
         for(int j = y; j <= y+off; j++){
             // �ڹ��� �κп� �´� Ű�κ�
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
    int cnt = 0;                 // �ڹ����� ���ۼ� 
    
    int m_size = M + (offset*2); // �ӽð����� �迭����
    vector<vector<int>> matrix(m_size, vector<int>(m_size));
    
    // �̸� ȸ���� Ű�� �����Ѵ�
    for(int i = 0; i < 4; i++){
        if(i == 0) { // �������� ���� ó�� ��� �״�� ����
            for(int j = 0; j <= offset; j++)
                for(int k = 0; k <= offset; k++)
                    ckey[0][j][k] = key[j][k];
        }
        else rot_key(i, offset+1); 
    }

    // �ӽ��� ��Ʈ������ �ڹ��踦 �����Ѵ�
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            matrix[i+offset][j+offset] = lock[i][j];
            if(lock[i][j] == 0) cnt++;
        }
    }

    // ���� ����Ž�� ����
     for(int i = 0; i < m_size-offset; i++){
         for(int j = 0; j < m_size-offset; j++){
             for(int k = 0; k < 4; k++){ // key ȸ���κ�
                 if(unlock(matrix, k, i, j, offset, cnt)) return true;
             }
         }
     }
        
    return answer;
}
