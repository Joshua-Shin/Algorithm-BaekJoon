#include <bits/stdc++.h>
using namespace std;
int dist[5][5];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool bfs(int x, int y, vector<string> board) {
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    dist[x][y] = 0;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        if(board[x][y] == 'P' && dist[x][y] != 0 && dist[x][y] <= 2) return false;
        if(dist[x][y] >= 3) return true;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(dist[nx][ny] != -1) continue;
            if(board[nx][ny] == 'X') continue;
            dist[nx][ny] = dist[x][y]  + 1;
            q.push({nx, ny});
        }
    }
    return true;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place: places) {
        for(int i = 0; i < place.size(); i++) {
            for(int j = 0; j < place[i].size(); j++) {
                if(place[i][j] != 'P') continue;
                if(!bfs(i, j, place)) {
                    answer.push_back(0);
                    goto out;
                }
            }
        }
        answer.push_back(1);
        out:;
    }
    return answer;
}