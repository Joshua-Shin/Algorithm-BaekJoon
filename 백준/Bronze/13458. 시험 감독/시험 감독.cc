#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> v(n);
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> a >> b;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        v[i] -= a;
        ans++;
        if(v[i] <= 0) continue;
        if(v[i] % b == 0) ans += v[i] / b;
        else ans += (v[i] / b + 1);
    }
    cout << ans << '\n';
}