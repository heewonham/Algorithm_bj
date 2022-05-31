import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.*;

public class bj9465_스티커 {
    private static final int MAX = -1;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();
        int test = Integer.parseInt(br.readLine());

        while(test-- > 0){
            // 1. input
            int n = Integer.parseInt(br.readLine());
            int[][] sticker = new int[2][n];
            int[][] answer = new int[2][n];
            StringTokenizer st1 = new StringTokenizer(br.readLine());
            StringTokenizer st2 = new StringTokenizer(br.readLine());

            for(int i = 0; i < n; i++){
                sticker[0][i] = Integer.parseInt(st1.nextToken());
                sticker[1][i] = Integer.parseInt(st2.nextToken());
                answer[0][i] = answer[1][i] = MAX;
            }

            // 2. dp
            result.append(Math.max(dp(sticker,answer,0,0,n), dp(sticker,answer,1,0,n))+"\n");
        }

        // 3. output
        System.out.println(result);
    }
    static int dp(int[][] sticker, int[][] answer, int r, int c, int n){
        if(r >= 2 || c >= n) return 0;
        if(answer[r][c] != -1){
            return answer[r][c];
        }

        // 갱신
        int ans1 = sticker[r][c] + dp(sticker,answer,(r+1)%2, c+1, n);
        int ans2 = sticker[r][c] + dp(sticker,answer, r, (c+2), n);
        int ans3 = sticker[r][c] + dp(sticker,answer, (r+1)%2, (c+2), n);

        answer[r][c] = Math.max(ans1, ans2);
        return answer[r][c] = Math.max(answer[r][c], ans3);
    }
}
