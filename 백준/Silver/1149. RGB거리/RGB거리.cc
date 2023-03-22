#include <bits/stdc++.h>
using namespace std;
int dp[1001][3];
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    dp[1][1] = v[0][1];
    dp[1][0] = v[0][0];
    dp[1][2] = v[0][2];
    for(int i = 2; i<=n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + v[i-1][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + v[i-1][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + v[i-1][2];
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    return 0; 
}