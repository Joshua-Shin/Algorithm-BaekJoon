#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[1000001], tree[1000001];
int cache[1000001][2];
void mkTree(int cur, int prev) {
    for(int nx : adj[cur]) {
        if(nx == prev) continue;
        tree[cur].push_back(nx);
        mkTree(nx, cur);
    }
}
int dp(int cur, bool isAdopter) {
    int &ret = cache[cur][isAdopter];
    if(ret != -1) return ret;
    ret = 0;
    if(!isAdopter)
        for(auto nx: tree[cur])
            ret += dp(nx, true) + 1;
    else
        for(auto nx: tree[cur])
            ret += min(dp(nx, true) + 1, dp(nx, false));
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    mkTree(1, -1);
    memset(cache, -1, sizeof(cache));
    cout << min(dp(1, false), dp(1, true) + 1) << '\n';
}