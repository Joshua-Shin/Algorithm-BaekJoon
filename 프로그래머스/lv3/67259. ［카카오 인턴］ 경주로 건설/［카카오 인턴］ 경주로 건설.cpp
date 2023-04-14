#include <bits/stdc++.h>
using namespace std;
int answer = 2e9;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int costCache[25][25][4];
int n;
vector<vector<int>> copy_board;
int findDir(int x, int y, int nx, int ny) {
    if(x==nx) return nx > x ? 0 : 2; /// ??????
    else return ny > y ? 3 : 1;
}
void dfs(int x, int y, int cost, int direction) {
    if(cost >= answer) return;
    if(x==n-1 && y == n-1) {
        answer = min(answer, cost);
        return;
    }
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >=n || ny < 0 || ny >= n || copy_board[nx][ny]==1) continue;
        int nextDir = findDir(x, y, nx, ny);
        int nextCost = (nextDir == direction || direction == -1) ? cost + 100 : cost + 600;
        if(costCache[nx][ny][nextDir] > nextCost) {
            costCache[nx][ny][nextDir] = nextCost;
            dfs(nx, ny, nextCost, nextDir);
        }
    }
    return;
}
int solution(vector<vector<int>> board) {
    copy_board = board;
    n = board.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                costCache[i][j][k] = 2e9;
    dfs(0, 0, 0, -1);
    return answer;
}