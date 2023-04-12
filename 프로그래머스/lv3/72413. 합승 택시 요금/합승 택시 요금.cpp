#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> adj[202]; // 정점, 비용
int go(int start, int end) {
    // 비용, 정점
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, 2e9);
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        int x = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[x] < cost) continue;
        if(x == end) return dist[x];
        for(auto e: adj[x]) {
            int nx = e.first;
            int nCost = e.second + cost;
            if(nCost >= dist[nx]) continue;
            dist[nx] = nCost;
            pq.push({dist[nx], nx});
        }
    }
    return dist[end];
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2e9;
    ::n = n;
    for(auto f: fares) {
        int a, b, c;
        a = f[0]; b = f[1]; c = f[2];
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        sum += go(s, i) + go(i, a) + go(i, b);
        answer = min(sum, answer);
    }
    return answer;
}