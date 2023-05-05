class Solution {
    public String solution(String s) {
        String answer = "";
        String [] ss = s.split(" ", -1);
        for(int i = 0; i < ss.length; i++) {
            String temp = "";
            for(int j = 0; j < ss[i].length(); j++) {
                if(j % 2 == 0) temp += Character.toUpperCase(ss[i].charAt(j));
                else temp += Character.toLowerCase(ss[i].charAt(j));
            }
            if(i != ss.length -1) temp += " ";
            answer += temp;
        }
        return answer;
    }
}
// 4, 5, 8, 9, 11