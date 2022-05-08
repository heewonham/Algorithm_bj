import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.ArrayList;

class 오픈채팅방 {
    public String[] solution(String[] record) {
        Map<String, String> userIdMap = new HashMap<>();

        for(String r : record){
            String[] contents = r.split(" ");
            if(!contents[0].equals("Leave")){
                userIdMap.put(contents[1],contents[2]);
            }
        }

        List<String> list = new ArrayList<>();
        for(String r : record){
            String[] contents = r.split(" ");
            if(contents[0].equals("Enter")){
                list.add(String.format(userIdMap.get(contents[1])+"님이 들어왔습니다."));
            }else if(contents[0].equals("Leave")){
                list.add(String.format(userIdMap.get(contents[1])+"님이 나갔습니다."));
            }
        }

        return list.toArray(new String[list.size()]);
    }
}
