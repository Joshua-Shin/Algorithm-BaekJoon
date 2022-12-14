#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int p[100001];
void bfs(int x) {
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx: adj[x]) {
            if(p[x]==nx) continue;
            p[nx] = x;
            q.push(nx);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i = 2; i<=n; i++)
        cout << p[i] << '\n';
    return 0;
}