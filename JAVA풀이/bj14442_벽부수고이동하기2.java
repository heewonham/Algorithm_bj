import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.LinkedList;
        import java.util.List;
        import java.util.Queue;
        import java.util.StringTokenizer;

public class bj14442_벽부수고이동하기2 {
    static int[] mr = {0,0,1,-1}, mc = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        String[] map = new String[R];
        for(int i = 0; i < R; i++){
            map[i] = br.readLine();
        }

        // output
        System.out.println(bfs(R, C, K, map));
    }
    static int bfs(int R, int C, int K, String[] map){

        Queue<Integer> q = new LinkedList<>();
        q.addAll(List.of(0, 0, 0, 1));
        boolean[][][] visited = new boolean[R][C][K+1];
        visited[0][0][0] = true;

        while(!q.isEmpty()){
            int curR = q.poll();
            int curC = q.poll();
            int k = q.poll();
            int cnt = q.poll();

            if(curR == R-1 && curC == C-1){ return cnt; }

            for(int i = 0; i < 4; i++){
                int nextR = curR + mr[i];
                int nextC = curC + mc[i];
                if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                if(nextR == R-1 && nextC == C-1){ return cnt+1; }
                // 벽이 있으면 부시고 가기
                if(map[nextR].charAt(nextC) == '1' && k < K && !visited[nextR][nextC][k+1]) {
                    visited[nextR][nextC][k+1] = true;
                    q.addAll(List.of(nextR, nextC, k+1, cnt+1));
                }
                if(!visited[nextR][nextC][k] && map[nextR].charAt(nextC) == '0') {
                    visited[nextR][nextC][k] = true;
                    q.addAll(List.of(nextR, nextC, k, cnt + 1));
                }
            }
        }
        return -1;
    }
}
