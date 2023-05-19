#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    bool dp[1005][1005];
    dp[1][true] = false;
    dp[1][false] = true;
    dp[2][true] = true;
    dp[2][false] = false;
    dp[3][true] = false;
    dp[3][false] = true;
    dp[4][true] = true;
    dp[4][false] = false;
    for(int i = 5; i <= n; i++) {
        // 상근이가 1개 혹은 3개를 가져간 두가지 상황에서 하나의 상황만 상근이가 이겨면(true면) 상근이가 이김(true)임.
        dp[i][true] = (dp[i-1][false] || dp[i-3][false] || dp[i-4][false]);
        // 창영이가 1개 혹은 3개를 가져간 두가지 상황에서 하나의 상황만 창영이가 이기면(false면) 창영이가 이김(false)
        dp[i][false] = !(dp[i-1][true]==false || dp[i-3][true]==false || dp[i-4][true]==false);
    }
    if(dp[n][true] == true) cout << "SK" << '\n';
    else cout << "CY" << '\n';
}