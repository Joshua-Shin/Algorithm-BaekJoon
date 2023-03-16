#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> adj[20001]; // 정점, 비용
vector<int> dijkstra(int start) {
    vector<int> dist(n+1, 2e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 정점
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto e: adj[x]) {
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
    int m, st;
    cin >> n >> m >> st;
    for (int j = 0; j < m; j++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    auto ans = dijkstra(st);
    for(int i = 1; i<ans.size(); i++) {
        if(ans[i] == 2e9) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
}