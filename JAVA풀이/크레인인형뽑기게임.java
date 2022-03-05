import java.util.*;

public class 크레인인형뽑기게임 {
    class Solution {
        public int solution(int[][] board, int[] moves) {
            int answer = 0;
            int sz = board[0].length;
            Deque<Integer> dq = new LinkedList<>();

            // 크레인 뽑기
            for(int c : moves){
                int r = 0;
                while(r < sz && board[r][c-1] == 0){
                    r++;
                }
                if(r >= sz){
                    continue;
                }
                // 집어넣기
                if(!dq.isEmpty() && dq.peekFirst() == board[r][c-1]){
                    dq.pollFirst();
                    answer+=2;
                }else{
                    dq.push(board[r][c-1]);
                }
                board[r][c-1] = 0;
            }

            return answer;
        }
    }
}
