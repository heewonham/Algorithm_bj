import java.util.*;

class 튜플 {

    public int[] solution(String s) {

        String[] setList = getList(s);
        return findResult(setList);
    }

    String[] getList(String s){

        // parsing {{}} 삭제 , 콤마로 구분
        String[] list = s.split("\\},\\{");
        for(int i = 0; i < list.length; i++){
            list[i] = list[i].replaceAll("[{}]", "");
            list[i] = list[i].replaceAll(",", " ");
        }

        // 길이로 정렬
        Arrays.sort(list, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return o1.length() - o2.length();
            }
        });

        return list;
    }

    int[] findResult(String[] setList){

        Set<String> set = new HashSet<>();
        int[] answer = new int[setList.length];

        for(int i = 0; i < setList.length; i++){
            String[] tmp = setList[i].split(" ");
            for(int j = 0; j < tmp.length; j++){
                if(!set.contains(tmp[j])){
                    set.add(tmp[j]);
                    answer[i] = Integer.parseInt(tmp[j]);
                    break;
                }
            }
        }

        return answer;
    }
}
