import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class bj11437 {
    static int[] deep = null;
    static int[][] parent = null;
    static final int PIV = 17;
    static class Connect{
        private List<Integer> list = new ArrayList<>();

        public void addNode(int n){
            list.add(n);
        }

        public int getSize(){
            return list.size();
        }

        public int getNode(int idx){
            return list.get(idx);
        }
    }
    static Connect[] con = null;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        int n = Integer.parseInt(br.readLine());

        con = new Connect[n+1];
        deep = new int[n+1];
        parent = new int[PIV][n+1];

        // 용량 확보
        for(int i = 0; i <= n; i++){
            con[i] = new Connect();
        }

        // node 입력
        for(int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            con[a].addNode(b);
            con[b].addNode(a);
        }

        // 연결
        Queue<Integer> q = new LinkedList<>();
        q.add(1); // node
        q.add(1); // dept;
        int dept = 0;
        while(!q.isEmpty()){
            int curnode = q.poll();
            int curdept = q.poll();
            deep[curnode] = curdept;
            for(int i = 0; i < con[curnode].getSize(); i++){
                int next = con[curnode].getNode(i);
                if(deep[next] == 0){
                    q.add(next);
                    q.add(curdept+1);
                    parent[0][next] = curnode; // 부모 저장
                }
            }
        }

        // 조상
        for(int i = 1; i < PIV; i++){
            for(int j = 1; j <= n; j++){
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            sb.append(LCA(a,b)+"\n");
        }

        br.close();
        System.out.println(sb);
    }
    static int LCA(int a, int b){
        int tmp;
        if(deep[a] > deep[b]){
            tmp = a;
            a = b;
            b = tmp;
        }
        tmp = deep[b]-deep[a];
        for(int i = 0; i < PIV; i++){
            int bit = 1 << i;
            if((tmp & bit) == bit){
                b = parent[i][b];
            }
        }
        if(b == a) return a;

        for(int i = PIV-1; i>= 0; i--){
            if(parent[i][a] != parent[i][b]){
                a = parent[i][a];
                b = parent[i][b];
            }
        }
        return parent[0][a];
    }
}