#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int dist[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int bfs(int x, int y, int ix, int iy) {
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        if(x == ix && y == iy) return dist[x][y] / 2;
        q.pop();
        for(int k = 0; k < 4; k++) {
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

int solution(vector<vector<int>> r, int cx, int cy, int ix, int iy) {
    cx *= 2; cy *= 2; ix *= 2; iy *= 2;
    for (int i = 0; i < r.size(); i++)
        for (int j = 0; j < r[0].size(); j++) 
            r[i][j] *= 2;
    for(auto v: r) {
        int x1 = v[0]; int y1 = v[1]; int x2 = v[2]; int y2 = v[3];
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++) 
                board[i][j] = 1;
    }
    for(auto v: r) {
        int x1 = v[0]; int y1 = v[1]; int x2 = v[2]; int y2 = v[3];
        for(int i = x1 + 1; i <= x2 - 1; i++)
            for(int j = y1 + 1; j <= y2 - 1; j++) 
                board[i][j] = 0;
    }
    memset(dist, -1, sizeof(dist));
    return bfs(cx, cy, ix, iy);
}