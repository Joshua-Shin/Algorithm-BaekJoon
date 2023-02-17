#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int mod = 1'000'000'000;
ll cache[1000001];
ll dp(int n) {
    if(n==0 || n==1) return n;
    ll &ret = cache[n];
    if(ret != -1) return ret;
    return ret = (dp(n-1) + dp(n-2)) % mod;
}
ll dp2(int n) {
    if(n==0 || n==1) return n;
    ll &ret = cache[abs(n)];
    if(ret != -1) return ret;
    return ret = (dp2(n+2) - dp2(n+1)) % mod; // dp(0) - dp(-1) = 0 - 1 = -1
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(cache, -1, sizeof(cache));
    if(n > 0) {
        ll ans = dp(n);
        if(ans > 0)
            cout << 1 << '\n';
        else if(ans==0)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        cout << abs(ans) << '\n';
    }
    else if(n <0){
        ll ans = dp2(n);
        if(ans > 0)
            cout << 1 << '\n';
        else if(ans==0)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';
        cout << abs(ans) << '\n';
    }
    else {
        cout << 0 << '\n';
        cout << 0 << '\n';
    }
}