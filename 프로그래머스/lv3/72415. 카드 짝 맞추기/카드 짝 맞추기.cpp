#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> board;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int dist[4][4];
int bfs(pair<int, int> a, pair<int, int> b, vector<vector<int>> &board) {
    int x = a.first; int y = a.second;
    int x2 = b.first; int y2 = b.second;
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        if(x == x2 && y == y2) return dist[x][y];
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
        for(int k = 0; k < 4; k++) {
            int nx = x; 
            int ny = y;
            while(1) {
                nx += dx[k];
                ny += dy[k];
                if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                    nx -= dx[k];
                    ny -= dy[k];
                    break;
                }
                if(board[nx][ny] != 0) break;
            }
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return dist[x2][y2];
}
int solution(vector<vector<int>> board, int r, int c) {
    vector<pair<int, int>> card[7];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(board[i][j]!=0) {
                card[board[i][j]].push_back({i, j});
            }
        }
    }
    vector<int> v;
    for(int i = 1; i<=6; i++) {
        if(!card[i].empty()) v.push_back(i);
    }
    // d[x][0] : (card[v[x]][1] 제거 -> card[v[x]][0] 제거) 비용의 최소값
    // d[x][1] : (card[v[x]][0] 제거 -> card[v[x]][1] 제거) 비용의 최소값
    int n = v.size();
    int ans = 1e9;
    do {
        int d[6][2];
        vector<vector<int>> myBoard = board;
        d[0][0] = bfs({r, c}, card[v[0]][1], myBoard) + bfs(card[v[0]][1], card[v[0]][0], myBoard);
        d[0][1] = bfs({r, c}, card[v[0]][0], myBoard) + bfs(card[v[0]][0], card[v[0]][1], myBoard);
        myBoard[card[v[0]][1].first][card[v[0]][1].second] = 0;
        myBoard[card[v[0]][0].first][card[v[0]][0].second] = 0;
        for(int i = 1; i < n; i++) {
            d[i][0] = min(d[i-1][0] + bfs(card[v[i-1]][0], card[v[i]][1], myBoard),
                            d[i-1][1] + bfs(card[v[i-1]][1], card[v[i]][1], myBoard))
                            + bfs(card[v[i]][1], card[v[i]][0], myBoard);
            d[i][1] = min(d[i-1][0] + bfs(card[v[i-1]][0], card[v[i]][0], myBoard),
                            d[i-1][1] + bfs(card[v[i-1]][1], card[v[i]][0], myBoard))
                            + bfs(card[v[i]][0], card[v[i]][1], myBoard);
            myBoard[card[v[i]][1].first][card[v[i]][1].second] = 0;
            myBoard[card[v[i]][0].first][card[v[i]][0].second] = 0;                 
        }
        ans = min({ans, d[n-1][0], d[n-1][1]});
    } while (next_permutation(v.begin(), v.end()));
    return ans + v.size()*2;
}