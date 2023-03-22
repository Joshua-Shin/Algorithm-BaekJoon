#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[1000001];
    int pre[1000001];
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        int temp1 = 2e9, temp2 =2e9, temp3 = 2e9;
        if(i % 3 == 0) temp1 = dp[i/3];
        if(i % 2 == 0) temp2 = dp[i/2];
        temp3 = dp[i-1];
        if(min(min(temp1, temp2), temp3) == temp1) pre[i] = i/3;
        if(min(min(temp1, temp2), temp3) == temp2) pre[i] = i/2;
        if(min(min(temp1, temp2), temp3) == temp3) pre[i] = i-1;
        dp[i] = min(min(temp1, temp2), temp3) + 1;
        //cout << i << ' ' << dp[i] << '\n';
    }
    cout << dp[n] << '\n';
    while(1) {
        cout << n << ' ';
        if(n==1) break;
        n = pre[n];
    }
    cout << '\n';
    return 0;
}