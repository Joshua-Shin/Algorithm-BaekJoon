class Solution {
    public int[] solution(int n, int m) {
        int result1 = gcd(n, m);
        int result2 = n * m / result1;
        int[] answer = {result1, result2};
        return answer;
    }
    
    public int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
}