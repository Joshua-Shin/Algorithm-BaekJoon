#include <bits/stdc++.h>
using namespace std;
int arr[301];
int dp[301];
int main() {
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i<=n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[2];
    dp[3] = arr[3];
    for(int i = 4; i <= n-1; i++) {
        dp[i] = min(dp[i-2], dp[i-3]) + arr[i];
    }
    cout << sum - min(dp[n-1], dp[n-2]) << '\n';
    return 0;
}