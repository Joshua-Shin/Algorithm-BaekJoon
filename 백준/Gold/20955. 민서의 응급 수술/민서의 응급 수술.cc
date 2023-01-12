#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100001];
bool check[100001];
void dfs(int x) {
    if(check[x]) return;
    check[x] = true;
    for(auto nx: adj[x]) dfs(nx);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(check, false, sizeof(check));
    int groupCnt = 0;
    for(int i = 1; i <= n; i++) {
        if(check[i]) continue;
        dfs(i);
        groupCnt++;
    }
    cout << (groupCnt -1) + (groupCnt -1 + m) - (n - 1);
}