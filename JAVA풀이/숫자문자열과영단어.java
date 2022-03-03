import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String s) {
        int answer = 0;

        Map<String, Integer> word = new HashMap<>();
        word.put("zero", 0);
        word.put("one", 1);
        word.put("two", 2);
        word.put("three",3);
        word.put("four",4);
        word.put("five",5);
        word.put("six",6);
        word.put("seven",7);
        word.put("eight",8);
        word.put("nine",9);

        StringBuilder sb = new StringBuilder();
        int i = 0;
        while(i < s.length()){
            Character ch = s.charAt(i);
            if(ch-'0' >=0 && ch-'0' <= 9){
                sb.append(Character.toString(ch));
                i++;
            } else{
                StringBuilder test = new StringBuilder();
                boolean flag = false;
                for(; i < s.length() && !flag; i++){
                    Character t = s.charAt(i);
                    test.append(Character.toString(t));
                    if(word.containsKey(test.toString())){
                        sb.append(word.get(test.toString()));
                        flag = true;
                    }
                }
            }
        }

        answer = Integer.parseInt(sb.toString());
        return answer;
    }
}