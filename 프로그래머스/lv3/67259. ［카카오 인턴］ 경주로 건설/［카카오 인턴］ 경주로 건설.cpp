#include <bits/stdc++.h>
using namespace std;
int answer = 2e9;
int n;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int cache[26][26][5];
void dfs(int x, int y, int d, int cost, vector<vector<int>> &board) {
    if(x == n - 1 && y == n - 1) {
        answer = min(answer, cost);
    }
    int &ret = cache[x][y][d+1];
    if(ret != -1 && ret <= cost) return;
    ret = cost;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny]) continue;
        if(d == -1 || d == k) dfs(nx, ny, k, cost + 100, board);
        else dfs(nx, ny, k, cost + 600, board);
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    memset(cache, -1, sizeof(cache));
    dfs(0, 0, -1, 0, board);
    return answer;
}