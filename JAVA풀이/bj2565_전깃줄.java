import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class bj2565_전깃줄 {
    static class Line{
        private int s, e;
        public Line(int s, int e) {
            this.s = s;
            this.e = e;
        }
        public int getS() { return s; }
        public int getE() { return e; }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        int N = Integer.parseInt(br.readLine());
        List<Line> line = new ArrayList<>();
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            line.add(new Line(s,e));
        }
        Collections.sort(line, (a,b)->{return a.getS() - b.getS();});

        // init
        int[] connect1 = new int[N], connect2 = new int[N];
        int max1 = 1, max2 = 1;

        connect1[0] = line.get(0).getE();
        for(int i = 1; i < N; i++){
            int e = line.get(i).getE();
            max1 = step1(e, max1, connect1);
        }

        connect2[0] = line.get(N-1).getE();
        for(int i = N-2; i >= 0; i--){
            int e = line.get(i).getE();
            max2 = step2(e, max2, connect2);
        }

        System.out.println(N-Math.max(max1,max2));
    }
    static int step1(int e, int max, int[] connect){
        int idx = 0;
        for(; idx < max; idx++){
            if(connect[idx] > e) break; // 더작으면 중단
        }
        connect[idx] = e;
        return Math.max(max, idx+1);
    }
    static int step2(int e, int max, int[] connect){
        int idx = 0;
        for(; idx < max; idx++){
            if(connect[idx] < e) break; // 더 크면 중단
        }
        connect[idx] = e;
        return Math.max(max, idx+1);
    }
}
