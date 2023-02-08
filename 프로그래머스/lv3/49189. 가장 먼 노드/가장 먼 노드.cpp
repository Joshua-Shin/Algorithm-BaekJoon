#include <bits/stdc++.h>
using namespace std;
vector<int> adj[20001];
int dist[20001];
int maxDist;
void bfs(int x) {
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx: adj[x]) {
            if(dist[nx]!=-1) continue;
            dist[nx] = dist[x] + 1;
            if(dist[nx] > maxDist) maxDist = dist[nx];
            q.push(nx);
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto e: edge) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    memset(dist, -1, sizeof(dist));
    bfs(1);
    for(int i = 1; i<=n; i++)
        if(dist[i]==maxDist) answer++;
    return answer;
}