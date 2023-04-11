#include <bits/stdc++.h>
using namespace std;
bool check[501][501][4]; // check[x][y][k] : x,y 좌표의 노드이면서, k 방향으로 나가는 상황.
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int go(int x, int y, int k, vector<string> &grid) {
    int ret = 0;
    // cout << "x: " << x << " y: " << y << " k: "<< k << " result: " << ret << '\n';
    int n = grid.size(); 
    int m = grid[0].size();
    check[x][y][k] = true;
    queue<vector<int>> q;
    q.push({x, y, k});
    while(!q.empty()) {
        auto temp = q.front(); q.pop();
        x = temp[0]; y = temp[1]; k = temp[2];
        int nx = x + dx[k]; 
        int ny = y + dy[k];
        if(nx < 0) nx = n -1; 
        else if(nx == n) nx = 0; 
        if(ny < 0) ny = m - 1; 
        else if(ny == m) ny = 0;
        int nk;
        if(grid[nx][ny] == 'L') {
            if(k == 3) nk = 0;
            else nk = k + 1;
        } else if(grid[nx][ny] == 'R') {
            if(k == 0) nk = 3;
            else nk = k -1;
        } else if(grid[nx][ny] == 'S') {
            nk = k;
        }
        ret++;
        // cout << "x: " << nx << " y: " << ny << " k: "<< nk << " result: " << ret << '\n';
        if(check[nx][ny][nk]) return ret;
        check[nx][ny][nk] = true;
        q.push({nx, ny, nk});
    }
    return ret;
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    // 사이클의 끝은 처음 시작점으로 돌아왔고, 다음 곳으로 나가는 방향이 시작떄돠 동일할때. 사이클의 완성.
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j <grid[i].size(); j++) {
            for(int k = 0; k < 4; k++) {
                if(check[i][j][k]) continue;
                int temp = go(i, j, k, grid);
                answer.push_back(temp);
                // cout << "==========================" << '\n';
                // cout << "i: " << i << " j: " << j << " k: "<< k << " result: " << temp << '\n';
            }
        }
    }
    // 사이클의 길이 배열
    sort(answer.begin(), answer.end());
    return answer;
}