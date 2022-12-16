#include <bits/stdc++.h>
using namespace std;
int n, m;
int cost[101][101];
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
        cost[a][b] = min(cost[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cost[i][j] != 1e9 ? cout << cost[i][j] << ' ' : cout << 0 << ' ';
        cout << '\n';
    }
    return 0;
}