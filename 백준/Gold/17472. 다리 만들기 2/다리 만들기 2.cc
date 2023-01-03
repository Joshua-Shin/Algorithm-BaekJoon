#include <bits/stdc++.h>
using namespace std;
int board[11][11];
int p[100001];
int n, m;
int getParent(int x) {
    if (p[x] == x) return x;
    return p[x] = getParent(p[x]);
}
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x < y) p[y] = x;
    else p[x] = y;
}
bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}
void initiateParentTable(int n) {
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
vector <tuple<int, int, int>> edge;
int kruskal (int n, int m) { // 정점개수, 간선개수
    int cnt = 0, answer = 0;
    for(int i = 0; i< m ; i++) {
        auto [cost, a, b] = edge[i];
        if(isSameParent(a, b)) continue;
        answer += cost;
        unionParent(a, b);
        if(++cnt == n-1) break;
    }
    if(cnt != n-1) answer = -1;
    return answer;
}
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int check[11][11];
void bfs(int x, int y, int code) {
    queue<pair<int, int>> q;
    check[x][y] = code;
    q.push({x, y});
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (check[nx][ny] != -1) continue;
            if (board[nx][ny]==0) continue;
            check[nx][ny] = code;
            q.push({nx, ny});
        }
    }
    return;
}
void setEdge(int x, int y) {
    int curCode = check[x][y];
    for(int k = 0; k< 4; k++) {
        int nx = x, ny = y;
        int dist = 1;
        bool find = false;
        while(1) {
            nx += dx[k];
            ny += dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if (board[nx][ny]) {
                if(check[nx][ny]==curCode) break;
                if(dist <= 2) break;
                find = true;
                break;
            }
            dist++;
        }
        if(find) edge.push_back({--dist, curCode, check[nx][ny]});
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    // test
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }

    int cnt = 0;
    memset(check, -1, sizeof(check));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(board[i][j]==1 && check[i][j] == -1) {
                bfs(i, j, cnt);
                cnt++;
            }
    initiateParentTable(cnt);
    // cout << "cnt: " << cnt << '\n';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(board[i][j]) setEdge(i, j);
    sort(edge.begin(), edge.end());

    cout << kruskal(cnt, edge.size()) << '\n';
    return 0;
}