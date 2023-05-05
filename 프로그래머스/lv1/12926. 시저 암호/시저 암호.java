class Solution {
    public String solution(String s, int n) {
        String answer = "";
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ' ') {
                answer += ' ';
                continue;
            }
            int cnt = n;
            char ch = s.charAt(i);
            while((cnt--) > 0) {
                if(ch == 'z') ch = 'a';
                else if(ch == 'Z') ch = 'A';
                else ch = (char)((int)ch + 1);
            }
            answer += ch;
        }
        return answer;
    }
}