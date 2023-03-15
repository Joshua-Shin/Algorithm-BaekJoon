#include <bits/stdc++.h>
using namespace std;
int n; // 정점개수
vector<pair<int, int>> adj[20001]; // 정점, 가중치
vector<int> dijkstra(int start) {
    // 비용, 정점 // 비용이 가장 적은애가 top으로 올라옴.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    // 정점번호가 1부터 시작할때, dist[x]: start에서 x정점까지 이동하는 최단 비용.
    vector<int> dist(n + 1, 2e9); 
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second;
        pq.pop(); // 다익스트라에서는 여기에서 방문이 이루어진다고 봐야하는게 맞는듯.
        // if (cost > dist[x]) continue; // 최적화인듯..?
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