import java.util.*;
class Solution {
    public int[] solution(long n) {
        // int[] answer = {};
        List<Integer> arr = new ArrayList<>();
        while(n > 0) {
            long a = n % 10;
            int b = (int)a;
            arr.add(b);            
            n /= 10;
        }
        int[] answer = new int[arr.size()];
        for(int i = 0; i < arr.size(); i++) {
            answer[i] = arr.get(i);
        }    
        return answer;
    }
}