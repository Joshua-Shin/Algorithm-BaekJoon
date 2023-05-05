class Solution {
    public String solution(String phone_number) {
        String answer = "";
        int n = phone_number.length();
        for(int i = 0; i < n - 4; i++) {
            answer += "*";
        }
        answer += phone_number.substring(n-4);
        return answer;
    }
}