#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1001];
int dist[1001];
int bfs(int x, int en) {
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        if(x==en) return dist[x];
        q.pop();
        for(int k = 0; k<adj[x].size(); k++) {
            int nx = adj[x][k].first;
            int nCost = adj[x][k].second;
            if(dist[nx]==-1) {
                dist[nx] = dist[x] + nCost;
                q.push(nx);
            }
        }
    }
    return 0;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<int> answer;
    while(m--) {
        int a, b;
        cin >> a >> b;
        memset(dist, -1, sizeof(dist));
        answer.push_back(bfs(a, b));
    }
    for(auto x: answer)
        cout << x << '\n';
    return 0;
}