#include <bits/stdc++.h>
using namespace std;
int n, m;
int cost[1001][1001]; // cost[x][y] = x에서 y로 가는데 드는 최소 비용
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i<=1000; i++)
        for(int j = 1; j<=1000; j++) {
            if(i==j) continue;
            cost[i][j] = 1e9;
        }
    for(int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    for(int k = 1; k<=n; k++) {
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=n; j++) {
                if(cost[i][j] < cost[i][k]+cost[k][j]) continue;
                cost[i][j] = cost[i][k]+cost[k][j];
            }
        }
    }
    vector<int> answer;
    for(int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        answer.push_back(cost[a][b]);
    }
    for(auto x: answer)
        cout << x << '\n';
    return 0;
}
// 노드의 번호가 1번부터 n번까지라는 말이 없눈디..