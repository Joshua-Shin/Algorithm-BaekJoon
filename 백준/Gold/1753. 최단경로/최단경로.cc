#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> adj[20001];
vector<int> solve(int st) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({dist[st], st});
    while(!pq.empty()) {
        auto [cost, x] = pq.top();
        pq.pop();
        if(dist[x] != cost) continue;
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
    int start;
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    auto ans = solve(start);
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i] == INT_MAX) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
}