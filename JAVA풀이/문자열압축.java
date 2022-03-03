import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 문자열압축{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        int answer = -1;
        for(int i = 1; i <= s.length()/2; i++){
            int len = 0;

            // init
            int j = i, cnt = 1;
            String prev = s.substring(0,j), cur = "";

            while(j < s.length()){
                int end = (j+i) >= s.length() ? s.length() : (j+i);
                cur = s.substring(j,end);
                j = end;

                if(cur.equals(prev)){ // 같으면 카운터만 올리기
                    cnt++;
                } else{ // 같지 않으면 추가
                    len += findCount(cnt, i);
                    if(answer != -1 && len > answer){ break; }
                    cnt = 1;
                }
                prev = cur;
            }
            // 마지막 부분 저장
            len += findCount(cnt, cur.length());

            // answer
            if(answer == -1 || answer > len){
                answer = len;
            }
        }

        System.out.println(answer);
    }
    static int findCount(int cnt, int len){
        if(cnt == 1) return len;
        else{
            String c = Integer.toString(cnt);
            return c.length() + len;
        }
    }
}