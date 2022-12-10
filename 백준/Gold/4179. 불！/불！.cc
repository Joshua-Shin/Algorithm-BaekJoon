#include <bits/stdc++.h>
using namespace std;
int dist[1001][1001];
bool fire[1001][1001];
int n, m;
char board[1001][1001];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> fireSpot;
int bfs(int jx, int jy) {
    queue<vector<int>> q;
    dist[jx][jy] = 0;
    q.push({jx, jy, 0}); // 지훈 좌표, 지훈 코드
    for(auto spot : fireSpot) {
        fire[spot.first][spot.second] = true;
        q.push({spot.first, spot.second, 1}); // 불 좌표, 불 코드
    }
    while (!q.empty()) {
        auto v = q.front();
        int x, y;
        x = v[0]; y = v[1];
        q.pop();
        if(v[2]==0) { // 지훈
            if(fire[x][y]) continue;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) return dist[x][y] + 1;
                if(dist[nx][ny]!= -1) continue;
                if(board[nx][ny]!='.') continue;
                if(fire[nx][ny]) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny, 0});
            }
        }
        else { // 불
            for(int k = 0; k< 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(fire[nx][ny]) continue;
                if(board[nx][ny]=='#') continue;
                fire[nx][ny] = true;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int jx, jy;
    
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j];
            if(board[i][j]=='J') tie(jx, jy) = tie(i, j);
            else if(board[i][j]=='F') fireSpot.push_back({i, j});
        }
    }
    memset(dist, -1, sizeof(dist));
    int answer = bfs(jx, jy);
    answer != -1 ? cout << answer << '\n' : cout << "IMPOSSIBLE" << '\n';
    return 0;
}