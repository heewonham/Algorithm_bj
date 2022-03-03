import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class bj2042_구간합구하기 {
    static int n = 0, m = 0, k = 0;
    static Long[] seg = null;

    public static void main(String[] args){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try{
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            // n 크기에 따른 세그먼트 사이즈 구하기
            int sz = 2;
            while(true){
                if((1<<sz) > (n*2)) break;
                sz++;
            }
            seg = new Long[1<<sz];

            for(int i = 0; i < (1<<sz); i++){
                seg[i] = 0L;
            }

            // input 1
            for(int i = 0; i < n; i++){
                Long val = Long.parseLong(br.readLine());
                update(sz-1,i+1,val);
            }

            // input 2
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < m+k; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if(a == 1){ // b번째 수를 c로 변경
                    Long c = Long.parseLong(st.nextToken());
                    update(sz-1,b,c);
                } else{ // b번째 ~ c번째까지의 합
                    int c = Integer.parseInt(st.nextToken());
                    sb.append(query(sz-1, b,c)+"\n");
                }
            }

            // output
            System.out.println(sb);
        }catch(IOException e){
            e.printStackTrace();
        }
    }

    static void update(int sz, int idx, Long val){
        int h = (1<<sz)+idx;
        seg[h] = val;
        h /= 2;
        while(h > 0){
            // 조상노드
            seg[h] = seg[h*2] + seg[h*2+1];
            h /= 2;
        }
    }
    static Long query(int sz, int l, int r){
        l += (1<<sz);
        r += (1<<sz);
        Long ans = 0L;
        while(l <= r){
            if(l%2 == 1) ans += seg[l++];
            if(r%2 == 0) ans += seg[r--];
            l/=2;
            r/=2;
        }
        return ans;
    }
}