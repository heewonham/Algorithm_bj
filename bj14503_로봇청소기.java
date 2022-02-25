import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class bj14503_로봇청소기 {
    static int[] mr = {-1,0,1,0}, mc = {0,1,0,-1};
    static int[][] matrix = null;
    static boolean[][] visited = null;
    static int n = 0, m = 0, cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 세로와 가로크기
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        // 로봇청소기 위치
        st = new StringTokenizer(br.readLine());
        int robotR = Integer.parseInt(st.nextToken());
        int robotC = Integer.parseInt(st.nextToken());
        int robotDir = Integer.parseInt(st.nextToken());

        // 지도
        matrix = new int[n][m];
        visited = new boolean[n][m];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                matrix[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // dfs
        visited[robotR][robotC] = true;
        cnt++;
        dfs(robotR,robotC,robotDir);
        System.out.println(cnt);
    }

    static void dfs(int r, int c, int pos){

        // 왼쪽 방향에 청소하고 없다면 다시 회전해서 확인한다.
        for(int i = 3; i >= 0; i--){
            int idx = (pos+i)%4;
            int nextR = r + mr[idx];
            int nextC = c + mc[idx];
            if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
            if(matrix[nextR][nextC] == 1 || visited[nextR][nextC]) continue;
            visited[nextR][nextC] = true;
            cnt++;
            dfs(nextR,nextC,idx);
            return;
        }

        // 청소공간이 모두 없다면, 한칸 후진한다.
        int idx = (pos+2)%4;
        int nextR = r + mr[idx];
        int nextC = c + mc[idx];
        if(nextR >= 0 && nextR < n && nextC >= 0 && nextC < m
                && matrix[nextR][nextC] == 0){
            dfs(nextR,nextC,pos);
        }

        // 청소공간도 없고 후진도 할 수 없다면 중지한다.
        return;
    }
}
