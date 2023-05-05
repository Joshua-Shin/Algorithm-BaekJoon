import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        List <Integer> list = new ArrayList<>();
        Map <String, Integer> m = new HashMap<>();
        for(int i = 0; i < name.length; i++) {
            m.put(name[i], yearning[i]);
        }
        for(int i = 0; i < photo.length; i++) {
            int score = 0;
            for(int j = 0; j < photo[i].length; j++) {
                if(m.containsKey(photo[i][j]))
                    score += m.get(photo[i][j]);
            }
            list.add(score);
        }
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}