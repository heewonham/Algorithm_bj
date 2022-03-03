public class 로또의최고순위와최저순위{

    class Solution {
        public int[] solution(int[] lottos, int[] win_nums) {
            int[] answer = new int[2];

            int zero = 0, ok = 0;
            for(int i = 0; i < lottos.length; i++){
                if(lottos[i] == 0){
                    zero++;
                } else if(findNum(lottos[i], win_nums)){
                    ok++;
                }
            }

            answer[1] = findOrder(ok);
            answer[0] = findOrder(ok+zero);

            return answer;
        }

        boolean findNum(int n, int[] win_nums){
            for(int i = 0; i < win_nums.length; i++){
                if(n == win_nums[i]){
                    return true;
                }
            }

            return false;
        }

        int findOrder(int n){
            if(n == 6) return 1;
            else if(n == 5) return 2;
            else if(n == 4) return 3;
            else if(n == 3) return 4;
            else if(n == 2) return 5;
            else return 6;
        }
    }
}
