#include <bits/stdc++.h>
using namespace std;
string a, b;
int cache[1001][1001];
int dp(int cur1, int cur2) {
    if(cur1==a.size() || cur2==b.size()) return 0;
    int &ret = cache[cur1][cur2];
    if(ret != -1) return ret;
    if(a[cur1]==b[cur2]) return ret = dp(cur1+1, cur2+1) + 1;
    return ret = max(dp(cur1+1, cur2), dp(cur1, cur2+1));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0) << '\n';
    int p1 = 0, p2 = 0;
    string ans;
    while(cache[p1][p2] > 0) {
        if(cache[p1][p2]==cache[p1+1][p2]) p1++;
        else if(cache[p1][p2]==cache[p1][p2+1]) p2++;
        else {
            ans += a[p1]; p1++; p2++; 
        }
    }
    if(ans.size()) cout << ans << '\n';
    return 0;
}
