import java.util.*;

public class 다트게임 {
    class Solution {
        public int solution(String dartResult) {
            int answer = 0, idx = 0;
            int[] num = new int[3];
            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < dartResult.length(); i++){
                char ch = dartResult.charAt(i);
                if(ch-'0' >= 0 && ch-'0'<= 10){
                    sb.append(Character.toString(ch));
                }else if(ch == '*' || ch == '#'){
                    if(ch == '*'){
                        if(idx - 1 >= 0){
                            num[idx-1] *= 2;
                        }
                        if(idx - 2 >= 0){
                            num[idx-2] *= 2;
                        }
                    }else{
                        num[idx-1] *= -1;
                    }
                }else{
                    int n = 0;
                    int p = Integer.parseInt(sb.toString());
                    if(ch == 'S'){
                        n = p;
                    } else if(ch == 'D'){
                        n = (int)Math.pow(p,2);
                    } else{
                        n = (int)Math.pow(p,3);
                    }
                    num[idx++] = n;
                    sb = new StringBuilder();
                }
            }

            return num[0]+num[1]+num[2];
        }
    }
}
