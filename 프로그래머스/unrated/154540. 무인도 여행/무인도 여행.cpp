#include <bits/stdc++.h>
using namespace std;
bool check[102][102];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int bfs(int x, int y, vector<string> &maps) {
    int ret = 0;
    queue<pair<int, int>> q;
    check[x][y] = true;
    ret += (maps[x][y] - '0');
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
            if(maps[nx][ny] == 'X') continue;
            if(check[nx][ny]) continue;
            check[nx][ny] = true;
            ret += (maps[nx][ny] - '0');
            q.push({nx, ny});
        }
    }
    return ret;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i = 0; i<maps.size(); i++) {
        for(int j = 0; j<maps[0].size(); j++) {
            if(check[i][j]) continue;
            if(maps[i][j] == 'X') continue;
            int temp = bfs(i, j, maps);
            answer.push_back(temp);
        }
    }
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}