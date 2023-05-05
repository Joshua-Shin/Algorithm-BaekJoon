class Solution {
    public long solution(int a, int b) {
        long result1 = (long)b * (b+1) / 2;
        long result2 = (long)a * (a+1) / 2;
        if(b > a) return result1 - result2 + a;
        return result2 - result1 + b;
        
    }
}