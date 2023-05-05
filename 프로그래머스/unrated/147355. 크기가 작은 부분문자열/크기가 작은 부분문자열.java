class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        int n = t.length();
        int m = p.length();
        for(int i = 0; i <= n - m; i++) {
            String a = t.substring(i, i + m);
            if(cmp(a, p)) answer++;
        }
        return answer;
    }
    
    public boolean cmp(String a, String b) {
        int n = a.length();
        for(int i = 0; i < n; i++) {
            if(a.charAt(i) < b.charAt(i)) return true;
            else if(a.charAt(i) > b.charAt(i)) return false;
        }
        return true;
    }
    
    
}