#include <bits/stdc++.h>
using namespace std;
int n; // 정점개수
vector<pair<int, int>> adj[51]; // 정점, 가중치 // 정점 개수
// start에서 모든 정점까지의 최단 비용을 vector<int> dist에 담아 반환함.
vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, 2e9); // 정점번호가 1부터 시작할때, dist[x]: start에서 x정점까지 이동하는 최단 비용.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 정점. 비용이 가장 적은애가 top으로 올라옴.
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().first; // 지금까지 출발지에서 x까지 이동하는데 걸린 총 최단 비용. 갱신될 수 있음.
        int x = pq.top().second;
        pq.pop(); // 다익스트라에서는 여기에서 방문이 이루어진다고 봐야하는게 맞는듯.
        if(cost > dist[x]) continue; // 이미 저장된 값이 더 작다면 갱신한 필요가 없으니 스킵 아! 이미 더 적은 경로로 도달한 정점인데, 이게 pq에 남아있었기 때문에, 여기에서 걸르는거네..>= 라고 해서 등호까지 걸러버리면, 이제 진행되는 경로도 다 차단되니 안되고 딱 > 로만 하는거야.
        for(auto e: adj[x]) {
            int nx = e.first;
            int nCost = cost + e.second;
            if(nCost >= dist[nx]) continue; // 일반 bfs처럼 방문했냐 안했냐를 구분 안짓는 이유가 어차피 한번 방문했다가 다시 오는 경우에는 cost가 높기때문에 여기에서 다 걸러짐
            dist[nx] = nCost;
            pq.push({dist[nx], nx});
        }
    }
    return dist;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    n = N;
    map<pair<int, int>, int> m;
    for(auto r: road) {
        if(m[{r[0], r[1]}] == 0 || m[{r[0], r[1]}] > r[2]) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
            m[{r[0], r[1]}] = r[2];
            m[{r[1], r[0]}] = r[2];
        }
    }
    auto dist = dijkstra(1);
    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K) answer++;
    }
    return answer;
}