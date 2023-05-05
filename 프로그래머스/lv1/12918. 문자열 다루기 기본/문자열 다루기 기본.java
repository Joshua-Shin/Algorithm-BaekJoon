class Solution {
    public boolean solution(String s) {
        try {
            Integer.parseInt(s);
        } catch (Exception e) {
            return false;
        }
        if(s.length() == 4 || s.length() == 6)
            return true;
        return false;
    }
}