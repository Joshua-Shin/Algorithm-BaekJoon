#include <bits/stdc++.h>
using namespace std;
int n;
int cache[1001];
int go(int idx, vector<int> &v) {
    if(idx == n) return 0;
    int &ret = cache[idx];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = idx +1; i<n; i++) 
        if(v[i] < v[idx]) ret = max(ret, go(i, v) + 1);
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = 1;
    memset(cache, -1, sizeof(cache));
    for(int k = 0; k<n; k++) {
        ans = max(ans, go(k, v));
    }
    cout << ans << '\n';
    return 0;
}