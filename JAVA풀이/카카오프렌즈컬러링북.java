import java.util.LinkedList;
import java.util.Queue;

class 카카오프렌즈컬러링북 {
    public int[] mr = {0,0,1,-1}, mc = {1,-1,0,0};
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        boolean[][] visited = new boolean[m][n];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && picture[i][j] != 0){
                    int area = bfs(i, j, m, n, visited, picture);
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, area);
                }
            }
        }


        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
    int bfs(int r, int c, int m, int n, boolean[][] visited, int[][] pic){

        int cnt = 0;
        visited[r][c] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(r);
        q.add(c);

        while(!q.isEmpty()){
            int curR = q.poll();
            int curC = q.poll();
            cnt++;

            for(int i = 0; i < 4; i++){
                int nextR = curR + mr[i];
                int nextC = curC + mc[i];
                if(nextR < 0 || nextR >= m|| nextC < 0 || nextC >= n) continue;
                if(!visited[nextR][nextC] && pic[curR][curC] == pic[nextR][nextC]){
                    visited[nextR][nextC] = true;
                    q.add(nextR);
                    q.add(nextC);
                }
            }

        }

        return cnt;
    }
}
