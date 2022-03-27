import java.util.*;

class PRO_전화번호목록 {
    public boolean solution(String[] phone_book) {
        int len = phone_book.length;

        Arrays.sort(phone_book);

        for(int i = 1; i < len; i++){
            if(phone_book[i].startsWith(phone_book[i-1])){
                return false;
            }
        }
        return true;
    }
}
