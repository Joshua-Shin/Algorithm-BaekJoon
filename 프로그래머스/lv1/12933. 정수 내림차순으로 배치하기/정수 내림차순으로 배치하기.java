import java.util.*;

class Solution {
    public long solution(long n) {
        long answer = 0;
        List<Long> arr = new ArrayList<>();
        while(n > 0) {
            arr.add(n % 10);
            n /= 10;
        }
        Collections.sort(arr, Collections.reverseOrder());
        for(long a: arr) {
            answer *= 10;
            answer += a;
        }
        return answer;
    }
}