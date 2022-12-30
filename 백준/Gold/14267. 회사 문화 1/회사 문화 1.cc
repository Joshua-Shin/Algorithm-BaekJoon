#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[100001];
int cost[100001]; // cost[x] = x번 직원이 받은 총 칭찬 값
void bfs(int x) {
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx: adj[x]) {
            cost[nx] += cost[x];
            q.push(nx);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if(a==-1) continue;
        adj[a].push_back(i);
    }
    while(m--) {
        int a, b;
        cin >> a >> b;
        cost[a] += b;
    }
    bfs(1);
    for(int i = 1; i<=n; i++)
        cout << cost[i] << ' ';
    cout << '\n';
    return 0;
}