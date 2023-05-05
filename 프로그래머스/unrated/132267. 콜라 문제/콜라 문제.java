class Solution {
    public int solution(int a, int b, int n) {
        if(n < a) return 0;
        int getCnt = (n / a) * b;
        int remain = n - (n / a) * a;
        return (getCnt + solution(a, b, getCnt + remain));
    }
}