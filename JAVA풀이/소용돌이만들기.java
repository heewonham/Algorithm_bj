import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class 소용돌이만들기 {
    static int[] unClockR ={1,0,-1,0}, unClockC ={0,1,0,-1};
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] matrix = new int[n][n];

        unClock(n,matrix);

        // 확인
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(" "+matrix[i][j]+" ");
            }
            System.out.println();
        }
    }

    static void unClock(int n, int[][] matrix){
        int[][] start = {{-1,0},{n-1,-1},{n,n-1},{0,n}};
        for(int i = 0; i < 4; i++){
            int r = start[i][0];
            int c = start[i][1];
            int idx = i, cnt = n-1, num = 1;
            while(cnt >= 1){
                for(int j = 0; j < cnt; j++){
                    r += unClockR[idx];
                    c += unClockC[idx];
                    matrix[r][c] = num++;
                }
                idx = (idx+1)%4;
                cnt = (cnt-2) == 0 ? 1 : cnt-2;
            }
        }
    }
}
