import java.util.*;
class Solution {
    public int[] solution(String s) {
        
        List<Integer>list = new ArrayList<>();
        for(int i = 0; i < s.length(); i++) {
            char findCh = s.charAt(i);
            int cnt = 0;
            boolean flag = false;
            for(int j = i - 1; j >= 0; j--) {
                cnt++;
                if(s.charAt(j) == findCh) {
                    list.add(cnt);
                    flag = true;
                    break;
                }
            }
            if(!flag) list.add(-1);
        }
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}