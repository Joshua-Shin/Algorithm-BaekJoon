import java.util.*;
class Solution {
    public int[] solution(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int minValue = 1000000000;
        for(int i = 0; i < arr.length; i++) {
            list.add(arr[i]);
            minValue = Math.min(minValue, arr[i]);
        }
        list.remove(new Integer(minValue));
        if(list.size()==0) {
            int[] answer = {-1};
            return answer;
        }
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}