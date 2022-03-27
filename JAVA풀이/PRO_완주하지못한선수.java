import java.util.*;

class PRO_완주하지못한선수 {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        Arrays.sort(participant);
        Arrays.sort(completion);

        int len = participant.length;
        int i = 0;
        for(String com : completion){
            if(!com.equals(participant[i])){
                answer = participant[i];
                break;
            }
            i++;
        }

        if(answer.isEmpty()){
            return participant[i];
        }
        return answer;
    }
}