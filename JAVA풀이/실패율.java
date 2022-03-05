import java.util.*;

public class 실패율 {

    class Solution {
        class Stage implements Comparable<Stage>{
            private int stageNum;
            private double failRate;

            public Stage(int s, double f){
                this.stageNum = s;
                this.failRate = f;
            }

            public int getStageNum(){
                return this.stageNum;
            }

            public double getFailRate(){
                return this.failRate;
            }

            @Override
            public int compareTo(Stage a){
                if(Double.compare(a.getFailRate(),this.failRate)==0){
                    return this.stageNum-a.getStageNum();
                }
                else if(Double.compare(a.getFailRate(),this.failRate)==-1){
                    return -1;
                }else{
                    return 1;
                }
            }
        }
        public int[] solution(int N, int[] stages) {
            int[] answer = new int[N];

            // 인원수 체크
            int[] arr = new int[N+2];
            for(int i : stages){
                arr[i]++;
            }

            // N까지 계산
            Stage[] stage = new Stage[N];
            double cnt = (double)stages.length;
            for(int i = 0; i < N; i++){
                double rate;
                if(arr[i+1] == 0){
                    rate = 0;
                } else{
                    rate = arr[i+1]/cnt;
                }
                stage[i] = new Stage(i+1, rate);
                cnt -= arr[i+1];
            }

            Arrays.sort(stage);
            for(int i = 0; i < stage.length; i++){
                answer[i] = stage[i].getStageNum();
            }
            return answer;
        }
    }
}
