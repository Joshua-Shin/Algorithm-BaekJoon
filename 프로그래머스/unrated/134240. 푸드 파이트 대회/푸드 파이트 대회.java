class Solution {
    public String solution(int[] food) {
        String answer = "";
        for(int i = 1; i < food.length; i++) {
            int cnt = food[i] / 2;
            while(cnt-- > 0) {
                answer += String.valueOf(i);
            }
        }
        String s = answer;
        StringBuilder sb = new StringBuilder(s);
        s = sb.reverse().toString();
        
        answer += "0" + s;
        return answer;
    }
}