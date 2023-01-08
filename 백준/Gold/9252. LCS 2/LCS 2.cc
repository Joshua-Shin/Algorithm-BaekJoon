#include <bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int main() {
    string a, b;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j<= b.size(); j++) {
            if(a[i]== b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[a.size()-1][b.size()-1] << '\n';
    string s;
    int x = a.size()-1, y = b.size()-1;
    while(dp[x][y]) {
        if(dp[x][y]==dp[x-1][y]) x--;
        else if(dp[x][y]==dp[x][y-1]) y--;
        else {
            s += a[x];
            x--;
            y--;
        }
    }
    reverse(s.begin(), s.end());
    if(s.size()) cout << s << '\n';
    return 0;
}