#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;
pii matrix[102][102];
bool strt(int x, int y, int sel){
    
    if(sel == 0) // '기둥'일 경우
    {
        if(y == 0) return true;
        if(matrix[x][y-1].first) return true;
        if((x > 0 && matrix[x-1][y].second) || matrix[x][y].second) return true;
    }
    else{ // '보'일 경우 
        if((y > 0 && matrix[x][y-1].first)
           || (y > 0 && matrix[x+1][y-1].first)) return true;
        if((x > 0 && matrix[x-1][y].second) && matrix[x+1][y].second) return true;
    }
    return false;
}
bool destrt(int x, int y, int sel){
    bool chk = true;
    if(sel == 0){ // 기둥
        if(matrix[x][y+1].first && !strt(x,y+1,0)) return false;
        if(x > 0 && matrix[x-1][y+1].second && !strt(x-1,y+1,1)) return false;
        if(matrix[x][y+1].second && !strt(x,y+1,1)) return false;
    }
    else{ //보
        if(matrix[x+1][y].first && !strt(x+1,y,0)) return false;
        if(matrix[x+1][y].second && !strt(x+1,y,1)) return false;
        if(x > 0 && matrix[x-1][y].second && !strt(x-1,y,1)) return false;
        if(matrix[x][y].first && !strt(x,y,0)) return false;
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<int> plus;
    vector<int> minus;
    
    for(vector<int> a : build_frame){
        int x = a[0], y = a[1], z=a[2];
        if(a[3] == 1){ // 추가
            if(strt(x,y,z)) {
                if(z == 0) matrix[x][y].first = 1;
                else matrix[x][y].second = 1;
            }
        }
        else{
            if(z == 0){
                matrix[x][y].first = 0;
                if(!destrt(x,y,z)) matrix[x][y].first = 1;
            }
            else{
                matrix[x][y].second = 0;
                if(!destrt(x,y,z)) matrix[x][y].second = 1;
            }
        }
    }
    
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            
            if(matrix[i][j].first){
                answer.push_back({i,j,0});
            }
            if(matrix[i][j].second){
                answer.push_back({i,j,1});
            }
        }
    }
    
    return answer;
}
