import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class bj2094{
    static int[] year = null;
    static int[] rain = null;

    public static void main(String[] args){
        ArrayList<String> answer = new ArrayList<>();

        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());

            year = new int[n];
            rain = new int[n];

            StringTokenizer st = null;
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine());
                year[i] = Integer.parseInt(st.nextToken());
                rain[i] = Integer.parseInt(st.nextToken());
            }

            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int start = Integer.parseInt(st.nextToken());
                int end = Integer.parseInt(st.nextToken());
                answer.add(checkFact(start,end));
            }

            br.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        // 출력
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < answer.size(); i++){
            sb.append(answer.get(i)+"\n");
        }
        System.out.print(sb);
    }

    static int upperBound(int y){
        int s = 0, e = year.length;
        while(s < e){
            int m = (s + e) / 2;
            if(year[m] <= y) s = m+1;
            else e = m;
        }

        if(s-1 < 0) return 0;
        return s-1;
    }
    static int findMax(int s, int e){
        int ans = -1;
        if(s == e) return rain[s];
        if(s > e) return -1;

        for(int i = s; i <= e; i++){
            if(ans == -1 || ans < rain[i]){
                ans = rain[i];
            }
        }
        return ans;
    }
    static String checkFact(int s, int e){
        int sIdx = upperBound(s);
        int eIdx = upperBound(e);

        boolean sBe = (year[sIdx] == s);
        boolean eBe = (year[eIdx] == e);

        // mid s, e 구하기
        int msIdx = (year[sIdx] <= s) ? sIdx+1 : sIdx;
        int meIdx = (year[eIdx] >= e) ? eIdx-1 : eIdx;
        int m = findMax(msIdx,meIdx);

        // 예외 : 중간이 최고 수치면 - false
        if (m == 1000000000) return "false";

        // 1. Y와 X를 둘다 모르는 경우 - may be
        if (!sBe && !eBe) { return "maybe"; }
        // 2. Y만 모르는 경우 - X가 Z보다 큰지만 확인 - maybe, false
        else if(!sBe && eBe){
            // 예외 : X가 1이면 Z는 없어야 함
            if(rain[eIdx] == 1){
                if((e-s) < 2) return "maybe";
                else return "false";
            }

            if(m == -1 || m < rain[eIdx]) return "maybe";
            else return "false";
        }
        // 3. X만 모르는 경우 - Y가 Z보다 큰지만 확인 - maybe, false
        else if(sBe && !eBe){
            // 예외 : Y가 1이면 X는 1일수밖에없고, Z는 없어야 함.
            if(rain[sIdx] == 1){
                if((e-s) < 2) return "maybe";
                else return "false";
            }

            if(m == -1 || m < rain[sIdx]) return "maybe";
            else return "false";
        }
        // 4. X,Y 알고 있는 경우 - Y >= X, Z보다 X가 큰지, 모든 Z 있는지
        else{
            boolean all = ((e-s) == (eIdx-sIdx));
            // 예외 : X와 Y가 1인 경우, Z는 없어야한다.
            if(rain[sIdx] == 1 && rain[eIdx] == 1){
                if((e-s) < 2) return "true";
                else return "false";
            }

            if((rain[sIdx] >= rain[eIdx]) && (m == -1 || m < rain[eIdx])){
                if(all) return "true";
                else return "maybe";
            }else return "false";
        }
    }
}