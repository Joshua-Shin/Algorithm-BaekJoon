#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cache[91];
ll dp(int n) {
    if(n==0 || n==1) return n;
    ll &ret = cache[n];
    if(ret != -1) return ret;
    return ret = dp(n-1) + dp(n-2);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << dp(n);
}