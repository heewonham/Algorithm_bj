import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class bj14950_정복자 {
    static int[] par = null;
    static class City{
        private int e1, e2, w;
        public City(int e1, int e2, int w) {
            this.e1 = e1;
            this.e2 = e2;
            this.w = w;
        }
        public int getE1() { return e1; }
        public int getE2() { return e2; }
        public int getW() { return w; }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // input
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        List<City> list = new ArrayList<>();
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            list.add(new City(a,b,w));
        }

        // init
        par = new int[N+1];
        for(int i = 1; i < N+1; i++){
            par[i] = i;
        }

        int answer = 0, cnt = 0;

        // sort
        Collections.sort(list, (a,b)->{return a.getW() - b.getW();});

        // output
        for(int i = 0; i < list.size(); i++){
            int e1 = list.get(i).getE1();
            int e2 = list.get(i).getE2();
            if(getParent(e1) != getParent(e2)){
                union(e1,e2);
                answer += (list.get(i).getW() + (T * cnt++));
            }
        }
        System.out.println(answer);
    }

    static void union(int e1, int e2){
        int p1 = getParent(e1);
        int p2 = getParent(e2);
        if(p1 > p2){ par[p1] = p2; }
        else{ par[p2] = p1; }
    }
    static int getParent(int n){
        if(n == par[n]) return n;
        return par[n] = getParent(par[n]);
    }
}
