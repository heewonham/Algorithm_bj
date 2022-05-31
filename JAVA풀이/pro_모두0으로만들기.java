import java.util.*;

class Solution {
    long sum = 0;
    public long solution(int[] a, int[][] edges) {
        int sz = a.length;

        // init
        List<Integer>[] connect = new List[sz];
        long[] b = new long[sz];
        for(int i = 0; i < sz; i++){
            sum += a[i];
            b[i] = a[i];
            connect[i] = new ArrayList<Integer>();
        }

        // no answer case
        if(sum != 0) return -1;

        // connection
        for(int[] e : edges){
            int e1 = e[0], e2 = e[1];
            connect[e1].add(e2);
            connect[e2].add(e1);
        }

        // DFS
        dfs(connect, b, 0,0);
        return sum;
    }
    void dfs(List<Integer>[] con, long[] weight, int cur, int parent){

        // 자식으로 내려가기
        for(int i = 0; i < con[cur].size(); i++){
            if(con[cur].get(i) == parent) continue;
            dfs(con, weight, con[cur].get(i), cur);
        }

        // 현재 값에서 부모로 올리기
        weight[parent] += weight[cur];
        this.sum += Math.abs(weight[cur]);

    }
}