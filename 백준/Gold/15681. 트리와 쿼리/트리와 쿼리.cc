#include <bits/stdc++.h>
using namespace std;
int n, r, q, u, v, root;
vector<int> adj[100001];
int p[100001];
int cache[100001];
int bfs(int x) {
    int cnt = 1;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx : adj[x]) {
            if(nx == p[x]) continue;
            p[nx] = x;
            q.push(nx);
            cnt++;
        }
    }
    return cache[x] = cnt;
}
int cnt(int cur) {
    int &ret = cache[cur];
    if(ret!= -1) return ret;
    ret = 1;
    for(auto nx : adj[cur]) {
        if(nx==p[cur]) continue;
        ret += cnt(nx);
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // bfs 돌면서 부모노드 갱신
    // 입력받은 값을 루트로 bfs 돌리면서 카운트
    cin >> n >> r >> q;
    for(int i = 0; i<n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(r);
    memset(cache, -1, sizeof(cache));
    vector<int> answer;
    for(int i = 0; i<q; i++) { // O(Q) == 10^5
        cin >> root;
        answer.push_back(cnt(root));
    }
    for(auto x: answer) {
        cout << x << '\n';
    }
    return 0;
}