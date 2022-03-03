import java.util.*;

public class 키패드누르기 {
    class Solution {
        class Pos{
            private int r;
            private int c;

            public Pos(int r, int c){
                this.r = r;
                this.c = c;
            }

            public int getR(){
                return r;
            }

            public int getC(){
                return c;
            }
        }
        public String solution(int[] numbers, String hand) {
            StringBuilder answer = new StringBuilder();

            Map<Integer, Pos> map = new HashMap<>();
            init(map);

            // 왼손 위치, 오른손 위치
            Pos left = new Pos(3,0);
            Pos right = new Pos(3,2);

            for(int i = 0; i < numbers.length; i++){
                if(isLeft(map,numbers[i],left,right,hand)){
                    left = map.get(numbers[i]);
                    answer.append("L");
                }else{
                    right = map.get(numbers[i]);
                    answer.append("R");
                }
            }
            return answer.toString();
        }

        void init(Map<Integer, Pos> map){
            map.put(1,new Pos(0,0));
            map.put(2,new Pos(0,1));
            map.put(3,new Pos(0,2));
            map.put(4,new Pos(1,0));
            map.put(5,new Pos(1,1));
            map.put(6,new Pos(1,2));
            map.put(7,new Pos(2,0));
            map.put(8,new Pos(2,1));
            map.put(9,new Pos(2,2));
            map.put(0,new Pos(3,1));
        }

        // 왼쪽인지 오른쪽인지
        boolean isLeft(Map<Integer, Pos> map,int num, Pos left, Pos right, String hand){
            if(num == 1 || num == 4 || num == 7){
                return true;
            } else if(num == 3 || num == 6 || num == 9){
                return false;
            } else{
                // 2580인 경우 왼손과 오른손 위치를 파악 후 이동
                int curR = map.get(num).getR();
                int curC = map.get(num).getC();

                // 거리 파악
                int leftP = Math.abs(curR - left.getR()) + Math.abs(curC - left.getC());
                int rightP = Math.abs(curR - right.getR()) + Math.abs(curC - right.getC());

                // 둘의 거리가 같으면?
                if(leftP==rightP){
                    if(hand.equals("right")){
                        return false;
                    }else{
                        return true;
                    }
                }else{
                    if(leftP > rightP){
                        return false;
                    }else{
                        return true;
                    }
                }
            }
        }
    }
}
