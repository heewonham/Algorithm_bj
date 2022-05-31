import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class bj1261_알고스팟 {
    static int[] mr = {0,0,1,-1}, mc = {1,-1,0,0};
    private static final int INF = 10000000;
    static class Pos{
        private int cnt, r, c;

        public Pos(int r, int c, int cnt) {
            this.cnt = cnt;
            this.r = r;
            this.c = c;
        }

        public int getCnt() { return cnt; }
        public int getR() { return r; }
        public int getC() { return c; }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        int C = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        String[] map = new String[R];
        for(int i = 0; i < R; i++){
            map[i] = br.readLine();
        }

        // output
        System.out.println(bfs(R, C, map));
    }
    static int bfs(int R, int C, String[] map){

        PriorityQueue<Pos> q = new PriorityQueue<>(new Comparator<Pos>() {
            @Override
            public int compare(Pos o1, Pos o2) {
                return o1.getCnt() - o2.getCnt();
            }
        });
        q.add(new Pos(0,0,0));

        int[][] dist = new int[R][C];
        init(R,C,dist);
        dist[0][0] = 0;

        while(!q.isEmpty()){
            Pos cur = q.poll();
            for(int i = 0; i < 4; i++){
                int nextR = cur.getR() + mr[i];
                int nextC = cur.getC() + mc[i];
                if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;

                int n = Integer.parseInt(map[nextR].substring(nextC,nextC+1));
                if(dist[nextR][nextC] > dist[cur.getR()][cur.getC()] + n){
                    dist[nextR][nextC] = dist[cur.getR()][cur.getC()] + n;
                    q.add(new Pos(nextR, nextC, cur.getCnt()+n));
                }
            }
        }
        return dist[R-1][C-1];
    }
    static void init(int R, int C, int[][] dist){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                dist[i][j] = INF;
            }
        }
    }
}
