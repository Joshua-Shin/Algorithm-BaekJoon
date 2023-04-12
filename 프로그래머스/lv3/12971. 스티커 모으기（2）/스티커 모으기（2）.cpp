#include <bits/stdc++.h>
using namespace std;
int n;
int solution(vector<int> sticker) {
    n = sticker.size();
    if(n == 1) return sticker[0];
    if(n == 2) return max(sticker[0], sticker[1]);

    // 첫번째 스티커 뜯었을때. 
    int dp[100002][2];
    dp[1][true] = sticker[0];
    dp[1][false] = -2e9;
    for(int i = 2; i <= n - 1; i++) {
        dp[i][true] = dp[i-1][false] + sticker[i-1];
        dp[i][false] = max(dp[i-1][true], dp[i-1][false]);
    }
    int ans1 = max(dp[n-1][true], dp[n-1][false]);

    // 첫번째 스티커를 안뜯었을때
    int dp2[100002][2];
    dp2[1][true] = -2e9;
    dp2[1][false] = 0;
    for(int i = 2; i <= n; i++) {
        dp2[i][true] = dp2[i-1][false] + sticker[i-1];
        dp2[i][false] = max(dp2[i-1][true], dp2[i-1][false]);
    }
    int ans2 = max(dp2[n][true], dp2[n][false]);

    return max(ans1, ans2);
}