class Solution {
    public String solution(int a, int b) {
        int [] day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDay = b;
        for(int i = 0; i < a-1; i++) {
            totalDay += day[i];
        }
        totalDay -= 1;
        int remain = totalDay % 7;
        String [] yoil = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
        return yoil[remain];
    }
    // public String solution(int a, int b) {
    //     System.out.println("1월2일은: " + solution2(1, 2));
    //     return null;
    // }
}