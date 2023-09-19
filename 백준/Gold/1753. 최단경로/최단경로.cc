#include <bits/stdc++.h>
using namespace std;
int n, m, start;
vector<pair<int, int>> adj[20001];
vector<int> solve() {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost != dist[x]) continue;
        for(auto &e: adj[x]) {
            int nx = e.first;
            int nCost = cost + e.second;
            if(nCost >= dist[nx]) continue;
            dist[nx] = nCost;
            pq.push({dist[nx], nx});
        }
    }
    return dist;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
    }
    auto v = solve();
    for(int i = 1; i <= n; i++) {
        if(v[i] == INT_MAX) cout << "INF" << '\n';
        else cout << v[i] << '\n';
    }
}