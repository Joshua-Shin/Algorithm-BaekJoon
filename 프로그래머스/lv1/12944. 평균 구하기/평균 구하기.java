class Solution {
    public double solution(int[] arr) {
        double answer = 0;
        int n = arr.length;
        for(int a: arr) {
            answer += a;
        }
        return answer / n;
    }
}