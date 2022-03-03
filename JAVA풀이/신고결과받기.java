import java.util.*;

public class 신고결과받기 {

    public static void main(String[] args){
        String[] id_list = {"muzi", "frodo", "apeach", "neo"};
        String[] report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
        int k = 3;

        int[] ans = solution(id_list, report, k);
    }

    static int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];

        Map<String,Integer> map = new HashMap<>();
        List<Integer>[] reported = new List[id_list.length];

        //init
        for(int i = 0; i < id_list.length; i++){
            reported[i] = new ArrayList<>();
        }

        // id_list -> map
        for(int i = 0; i < id_list.length; i++){
            map.put(id_list[i], i);
        }

        // check report
        for(int i = 0; i < report.length; i++){
            StringTokenizer st = new StringTokenizer(report[i]);
            int s = map.get(st.nextToken());
            int e = map.get(st.nextToken());
            if(!reported[e].contains(s)){
                reported[e].add(s);
            }
        }

        // reported -> k 이상인
        for(int i = 0; i < id_list.length; i++){
            if(reported[i].size() >= k){
                for (Integer num : reported[i]) {
                    answer[num]++;
                }
            }
        }
        return answer;
    }
}