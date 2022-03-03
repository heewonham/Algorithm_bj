public class 신규아이디추천 {
    class Solution {
        public String solution(String new_id) {
            String answer = "";

            answer = new_id.toLowerCase(); // 1case
            answer = twoCase(answer); // 2case
            answer = threeCase(answer); // 3case
            answer = firstCheck(answer); // 4case : 첫번째문자열
            answer = lastCheck(answer); // 4case : 마지막문자열

            // 5. 아이디가 빈 문자열이면 a 대입
            if(answer.length() == 0){
                answer = "a";
            }

            // 6. 16자이상이라면 15자까지 저장
            if(answer.length() >= 16){
                answer = answer.substring(0,15);
            }
            answer = lastCheck(answer); // 마지막 문자열

            // 7. 두글자 이하면 마지막 글자를 길이 3이될때까지 추가
            if(answer.length() <= 2){
                char last = answer.charAt(answer.length()-1);
                for(int i = answer.length(); i < 3; i++){
                    answer += Character.toString(last);
                }
            }
            return answer;
        }

        boolean checkOk(char ch){
            if(ch-'0' >= 49 && ch-'0' <= 74){
                return true;
            } else if(ch-'0' >= 0 && ch-'0' <= 9 ){
                return true;
            } else if(ch == '-') {
                return true;
            } else if(ch == '_'){
                return true;
            } else if(ch == '.'){
                return true;
            } else{
                return false;
            }
        }

        String twoCase(String str){
            // 2. 소문자, 숫자, 빼기, 밑줄, 마침표 제외 모두 제거
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < str.length(); i++){
                char ch = str.charAt(i);
                if(checkOk(ch)){
                    sb.append(Character.toString(ch));
                }
            }
            return sb.toString();
        }
        String threeCase(String str){
            // 3. 마침표 2번 이상 -> 하나로
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < str.length(); i++){
                char ch = str.charAt(i);
                if(ch == '.'){
                    int j = i;
                    for(; j < str.length(); j++){
                        if(str.charAt(j) != '.') break;
                    }
                    sb.append(".");
                    i = j-1;
                } else{
                    sb.append(Character.toString(ch));
                }
            }
            return sb.toString();
        }
        String firstCheck(String str){
            int len = str.length();
            if(len > 0 && str.charAt(0) == '.'){
                str = str.substring(1);
            }
            return str;
        }

        String lastCheck(String str){
            int len = str.length();
            if(len > 0 && str.charAt(len-1) == '.'){
                str = str.substring(0,len-1);
            }
            return str;
        }
    }
}
