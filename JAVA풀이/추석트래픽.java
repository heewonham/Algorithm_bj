import java.util.*;
import java.util.stream.Collectors;

class 추석트래픽 {
    public int solution(String[] lines) {
        int answer = 0;
        int len = lines.length;
        int[][] times = new int[len][2];

        // parsing
        for(int i = 0; i < len; i++){
            String[] str = lines[i].split(" ");
            times[i][1] = findEndTime(str[1]);
            times[i][0] = findStartTime(times[i][1], str[2]);
        }

        // 시작과 끝을 기준으로 로그 수 구하기
        for(int[] time : times){
            answer = Math.max(answer, findTraffic(times, time[0]));
            answer = Math.max(answer, findTraffic(times, time[1]));
            System.out.println(time[0] + " "+ time[1]);
        }

        return answer;
    }

    int findEndTime(String t){
        t = t.replace(".", "");
        List<Integer> time = Arrays.stream(t.split(":"))
                .map(i -> Integer.parseInt(i))
                .collect(Collectors.toList());

        return ((((time.get(0) * 60) + time.get(1)) * 60) * 1000 + time.get(2));
    }

    int findStartTime(int start, String laps){
        double d = Double.parseDouble(laps.replace("s","")) * 1000;
        return start-(int)d+1;
    }

    int findTraffic(int[][] time, int s){

        int cnt = 0;
        int e = s + 999;

        for(int i = 0; i < time.length; i++){
            if(s <= time[i][1] && e >= time[i][0]){
                cnt++;
            }
        }
        return cnt;
    }
}
