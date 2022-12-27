#include <bits/stdc++.h>
using namespace std;
int n, r, q, u, v, root;
vector<int> adj[100001];
int cnt[100001];
bool check[100001];
int bfs(int cur) {
    check[cur] = true;
    cnt[cur] = 1;
    for(auto nx: adj[cur]) {
        if(check[nx]) continue;
        cnt[cur] += bfs(nx);
    }
    return cnt[cur];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r >> q;
    for(int i = 0; i<n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(check, false, sizeof(check));
    bfs(r);
    vector<int> answer;
    for(int i = 0; i<q; i++) {
        cin >> root;
        answer.push_back(cnt[root]);
    }
    for(auto x: answer)
        cout << x << '\n';
    return 0;
}