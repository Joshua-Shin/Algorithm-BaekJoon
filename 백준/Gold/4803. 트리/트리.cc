#include <bits/stdc++.h>
using namespace std;
vector<int> adj[501];
bool check[501];
int p[501];
bool bfs(int x) {
    bool flag = true;
    queue<int> q;
    q.push(x);
    check[x] = true;
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx: adj[x]) {
            if(nx == p[x]) continue;
            if(check[nx]) {
                flag = false;
                continue;
            }
            else {// check[nx]==false
                check[nx] = true;
                p[nx] = x;
                q.push(nx);
            }
        }
    }
    return flag;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc = 1;
    while(1) {
        int n, m;
        cin >> n >> m;
        if(n==0 && m==0) break;
        for(int i = 0; i<=500; i++)
            adj[i].clear();
        memset(check, false, sizeof(check));
        for (int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++) {
            if(check[i]==false)
                if(bfs(i))
                    cnt++;
        }
        cout << "Case " << tc << ": ";
        if(cnt==0)
            cout << "No trees." << '\n';
        else if(cnt==1)
            cout << "There is one tree." << '\n';
        else
            cout << "A forest of " << cnt << " trees." << '\n';
        tc++;
    }
    return 0;
}