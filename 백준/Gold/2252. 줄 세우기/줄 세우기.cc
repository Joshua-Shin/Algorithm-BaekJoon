#include <bits/stdc++.h>
using namespace std;
int n, m;
int deg[32001];
vector<int> adj[32001];
vector<int> result;
void topologicalSorting() {
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if(deg[i]==0) q.push(i);
    while(!q.empty()) {
        int x = q.front();
        result.push_back(x);
        q.pop();
        for(auto nx: adj[x]) {
            deg[nx]--;
            if(deg[nx]==0) q.push(nx);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        deg[b]++;
        adj[a].push_back(b);
    }
    topologicalSorting();
    for(auto x: result)
        cout << x << ' ';
    cout << '\n';
    return 0;
}