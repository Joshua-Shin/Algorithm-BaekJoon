#include <bits/stdc++.h>
using namespace std;
int n;
const int MX = 10005;
int arr[MX], cache[MX][2];
vector<int> tree[MX], adj[MX];
void mkTree(int cur, int prev) {
    for(auto nx: adj[cur]) {
        if(nx == prev) continue;
        tree[cur].push_back(nx);
        mkTree(nx, cur);
    }
}
int dp(int cur, bool isGreat) {
    int &ret = cache[cur][isGreat];
    if(ret != -1) return ret;
    ret = 0;
    if(isGreat)
        for(auto nx: tree[cur])
            ret += dp(nx, false);
    else
        for(auto nx: tree[cur])
            ret += max(dp(nx, false), dp(nx, true) + arr[nx]);
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mkTree(1, -1);
    memset(cache, -1, sizeof(cache));
    cout << max(dp(1, true) + arr[1], dp(1, false));
}