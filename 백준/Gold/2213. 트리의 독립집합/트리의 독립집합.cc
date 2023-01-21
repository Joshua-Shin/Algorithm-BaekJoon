#include <bits/stdc++.h>
using namespace std;
int n;
const int MX = 10'002;
int arr[MX];
vector<int> adj[MX], tree[MX];
int cache[MX][2];
vector<int> ans;
void mkTree(int cur, int prev) {
    for(auto nx: adj[cur]) {
        if(nx == prev) continue;
        tree[cur].push_back(nx);
        mkTree(nx, cur);
    }
}
int dp(int cur, bool isSelect) {
    int &ret = cache[cur][isSelect];
    if(ret != -1) return ret;
    ret = 0;
    if(isSelect)
        for(auto nx: tree[cur])
            ret += dp(nx, false);
    else
        for(auto nx: tree[cur])
            ret += max(dp(nx, false), dp(nx, true) + arr[nx]);
    return ret;
}
void go(int cur, bool isSelect) {
    if(isSelect) {
        ans.push_back(cur);
        for(auto nx: tree[cur])
            go(nx, false);
    }
    else
        for(auto nx: tree[cur])
            go(nx, cache[nx][0] < cache[nx][1] + arr[nx]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mkTree(1, -1);
    memset(cache, -1, sizeof(cache)); 
    int result1 = dp(1, false);
    int result2 = dp(1, true) + arr[1];
    cout << max(result1, result2) << '\n';
    go(1, result2 > result1);
    sort(ans.begin(), ans.end());
    for(auto x: ans) cout << x << ' ';
}