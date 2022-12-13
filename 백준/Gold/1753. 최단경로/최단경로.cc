#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> adj[20001];
vector<int> dijkstra(int x) {
    vector<int> dist(n+1, 2e9);
    dist[x] = 0;
    priority_queue <pair<int,int>> pq; // -비용, 정점.
    pq.push({0, x});
    while(!pq.empty()) {
        x = pq.top().second;
        int xCost = -pq.top().first;
        pq.pop();
        //if(xCost > dist[x]) continue; // ???
        for(int k = 0; k<adj[x].size(); k++) {
            int nx, nxCost;
            nx = adj[x][k].first;
            nxCost = adj[x][k].second + xCost;
            if(nxCost < dist[nx]) {
                dist[nx] = nxCost;
                pq.push({-nxCost, nx});
            }
        }
    }
    return dist;
}
int main() {
    cin >> n >> m;
    int start;
    cin >> start;
    for(int i = 0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<int> v = dijkstra(start);
    for(int i = 1; i<v.size(); i++) {
        if(v[i]==2e9) cout << "INF" << '\n';
        else cout << v[i] << '\n';
    }
    return 0;
}