#include <bits/stdc++.h>
using namespace std;
int tc, n, temp;
int dp[10001];
int coin[3];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> tc;
    for (int i = 0; i < 3; i++) coin[i] = i+1;
    dp[0] = 1;
    for(int i = 0; i < 3; i++)
        for(int j = coin[i]; j <= 10000; j++)
            dp[j] += dp[j - coin[i]];
    while(tc--) {
        cin >> temp;
        cout << dp[temp] << '\n';
    }
}