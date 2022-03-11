import java.util.*;

public class 거리두기확인하기 {
    class Solution {
        static int[] mr = {0,0,-1,1}, mc = {-1,1,0,0};
        public int[] solution(String[][] places) {
            int[] answer = new int[places.length];
            int idx = 0;

            for(String[] place: places){
                boolean flag = true;
                for(int i = 0; flag && i < 5; i++){
                    for(int j = 0; flag && j < 5; j++){
                        flag = bfs(i,j,place);
                    }
                }

                if(!flag) answer[idx++] = 0;
                else answer[idx++] = 1;
            }

            return answer;
        }
        static boolean bfs(int r, int c, String[] place){

            if(place[r].charAt(c) != 'P') return true;
            boolean[][] visited = new boolean[5][5];
            Queue<Integer> q = new LinkedList<>();
            q.add(r);
            q.add(c);
            q.add(0);
            visited[r][c]=true;

            while(!q.isEmpty()){
                int curR = q.poll();
                int curC = q.poll();
                int cnt = q.poll();

                for(int i = 0; i < 4; i++){
                    int nextR = curR + mr[i];
                    int nextC = curC + mc[i];
                    if(nextR < 0 || nextR >= 5 || nextC < 0 || nextC >= 5) continue;
                    if(cnt < 2 && !visited[nextR][nextC]){
                        visited[nextR][nextC] = true;
                        if(place[nextR].charAt(nextC) =='P'){
                            System.out.println("실패");
                            return false;
                        }
                        // 빈테이블이면 go
                        if(place[nextR].charAt(nextC) =='O'){
                            q.add(nextR);
                            q.add(nextC);
                            q.add(cnt+1);
                        }
                    }
                }
            }
            return true;
        }
    }
}
