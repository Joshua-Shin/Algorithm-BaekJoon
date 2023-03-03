#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int board[110][110];
int dist[110][110];
int solution(vector<vector<int>> r, int x, int y, int itemX, int itemY) {
    for(int i = 0; i < r.size(); i++) {
        for(int j = 0; j < r[0].size(); j++) {
            r[i][j] *= 2;
        }
    }
    x *= 2; y *= 2; itemX *= 2; itemY *= 2;
    for(int i = 0; i< r.size(); i++) {
        int x1, y1, x2, y2;
        x1 = r[i][0]; y1 = r[i][1];
        x2 = r[i][2]; y2 = r[i][3];
        for(int x = x1; x <= x2; x++) {
            for(int y = y1; y <= y2; y++) {
                board[x][y] = 1;
            }
        }
    }
    for(int i = 0; i< r.size(); i++) {
        int x1, y1, x2, y2;
        x1 = r[i][0]; y1 = r[i][1];
        x2 = r[i][2]; y2 = r[i][3];
        for(int x = x1 + 1; x <= x2 - 1; x++) {
            for(int y = y1 + 1; y <= y2 -1; y++) {
                board[x][y] = 0;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        if(x == itemX && y == itemY) return dist[x][y] / 2;
        q.pop();
        for(int k = 0; k< 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(!board[nx][ny]) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return 0;
}
























