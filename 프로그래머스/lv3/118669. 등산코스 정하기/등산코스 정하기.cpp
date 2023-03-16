#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[50001];
bool isSummit[50001];
int n;
vector<int> go(vector<int> & gates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> intensity(n+1, 2e9);
    vector<pair<int, int>> v;
    for(auto g: gates) {
        pq.push({0, g});
        intensity[g] = 0;
    }
    while(!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(isSummit[x]) {
            v.push_back({cost, x});
            continue;
        }

        if(cost > intensity[x]) continue;
        for(auto e: adj[x]) {
            int nx = e.first;
            int nCost = max(cost, e.second);
            if(intensity[nx] <= nCost) continue;
            intensity[nx] = nCost;
            pq.push({intensity[nx], nx});
        }
    }
    sort(v.begin(), v.end());
    return {v[0].second, v[0].first};
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto p: paths) {
        adj[p[0]].push_back({p[1], p[2]});
        adj[p[1]].push_back({p[0], p[2]});
    }
    for(auto s: summits) isSummit[s] = true;
    ::n = n;
    return go(gates);
}