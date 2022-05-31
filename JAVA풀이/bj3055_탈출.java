import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class bj3055_탈출 {
    static int[] mr = {0,0,1,-1}, mc = {1,-1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        int sr = 0, se = 0;
        StringBuilder[] map = new StringBuilder[R];
        Queue<Integer> water = new LinkedList<>();

        for(int i = 0; i < R; i++){
            map[i] = new StringBuilder(br.readLine());
            for(int j = 0; j < C; j++){
                if(map[i].charAt(j) == 'S'){ sr = i; se = j; }
                else if(map[i].charAt(j) == '*'){ water.add(i); water.add(j); }
            }
        }

        // exec
        int answer = bfs(R, C, sr, se, water, map);

        // output
        if(answer == -1){
            System.out.println("KAKTUS");
        }else{
            System.out.println(answer);
        }
    }
    static int bfs(int R, int C, int sr, int se, Queue<Integer> water, StringBuilder[] map){

        Queue<Integer> q = new LinkedList<>();
        q.add(sr);
        q.add(se);
        q.add(0);
        boolean[][] visited = new boolean[R][C];
        visited[sr][se] = true;

        while(!q.isEmpty()){
            // 물 이동
            int sz = water.size() / 2;
            while(sz-- > 0){
                int wR = water.poll();
                int wC = water.poll();
                water.addAll(List.of(wR, wC));

                for(int i = 0; i < 4; i++){
                    int nextR = wR + mr[i];
                    int nextC = wC + mc[i];
                    if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                    if(map[nextR].charAt(nextC) == '.'){
                        map[nextR].setCharAt(nextC, '*');
                        water.addAll(List.of(nextR, nextC));
                    }
                }
            }

            // 두더지 이동
            sz = q.size()/3;
            while(sz-- > 0){
                int curR = q.poll();
                int curC = q.poll();
                int cnt = q.poll();
                for(int i = 0; i < 4; i++){
                    int nextR = curR + mr[i];
                    int nextC = curC + mc[i];
                    if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                    if(map[nextR].charAt(nextC) == 'D'){
                        return cnt+1;
                    }
                    if(!visited[nextR][nextC]&& map[nextR].charAt(nextC) == '.'){
                        visited[nextR][nextC] = true;
                        q.addAll(List.of(nextR, nextC, cnt+1));
                    }
                }
            }
        }
        return -1;
    }
}
