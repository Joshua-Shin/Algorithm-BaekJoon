#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int dp[1000001];
    dp[2] = dp[3] = 1;
    for(int i = 4; i<=n; i++) {
        int result = dp[i -1] + 1;
        if(i % 3 == 0) result = min(result, dp[i / 3] + 1);
        if(i % 2 == 0) result = min(result, dp[i / 2] + 1);
        dp[i] = result;
    }
    cout << dp[n];
}