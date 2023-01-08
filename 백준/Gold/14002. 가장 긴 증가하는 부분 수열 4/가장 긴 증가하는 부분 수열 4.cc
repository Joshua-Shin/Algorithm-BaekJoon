#include <bits/stdc++.h>
using namespace std;
int n, ans;
int cache[1001];
int go(int idx, vector<int> &v) {
    if(idx==n) return 0;
    int &ret = cache[idx];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = idx + 1; i< n; i++)
        if(v[idx] < v[i])
            ret = max(ret, go(i, v)+1);
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i<n; i++)
        ans = max(ans, go(i, v));
    cout << ans << '\n';
    vector<int> ansSeq;
    int findIdx;
    for(int i = 0; i<n; i++)
        if(ans == cache[i]) {
            ans--;
            findIdx = i;
            ansSeq.push_back(v[i]);
            break;
        }
    for(int i = findIdx + 1; i<n && ans; i++)
        if(cache[i]==ans && v[i] > v[findIdx]) {
            ans--;
            findIdx = i;
            ansSeq.push_back(v[i]);
        }
    for(auto x: ansSeq) cout << x << ' ';
    return 0;
}