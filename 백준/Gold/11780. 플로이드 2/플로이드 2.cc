#include <bits/stdc++.h>
using namespace std;
int n, m;
int cost[101][101];
int nxt[101][101]; //  i에서 j까지 최단거리로 가는데 i에서 이동하는 다음 정점
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost[i][j] = 1e9;

    for (int i = 1; i <= n; i++)
        cost[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(cost[a][b] > c) {
            cost[a][b] = c;
            nxt[a][b] = b;
        }
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if(cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(cost[i][j] == 1e9) cost[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << cost[i][j] << ' ';
        cout << '\n';
    }

    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            if(cost[i][j]==0) {
                cout << 0 << '\n';
                continue;
            }
            vector <int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << ' ';
            for(auto x: path) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}