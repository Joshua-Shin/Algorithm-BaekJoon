class Solution {
    public long solution(long n) {
        long answer = 0;
        long result = (long)Math.sqrt(n);
        if(result * result == n) return (result+1) * (result+1);
        return -1;
    }
}