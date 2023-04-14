#include <bits/stdc++.h>
using namespace std;
// dp 냄새가 나긴 하는데, 일단 dfs로 풀어보자.
int dx[] = {1, 0, -1, 0}; // 하, 우, 상, 좌
int dy[] = {0, 1, 0, -1};
int answer = 2e9;
int n, m;
bool check[26][26];
int cache[26][26][4];
// 현위치에서 도착지까지 가는데 필요한 최소한의 가상 비용
int minCost(int x, int y) {
    int ret = ((n-1 -x) + (m-1 -y)) * 100;
    if(x==n-1 || y == n-1) return ret;
    return ret + 500;
}
void go(int x, int y, int d, int sum, vector<vector<int>> &board) {
    // 지금 순간에서 가장 빨리 간다 쳐도, 현재 answer보다 값이 클때, 더 이상 진행할 필요 없음.
    // 이게 문제점이.. answer가 일단 한번이라도 갱신이 되어야 이 로직이 의미를 갖는데,,,
    if(minCost(x, y) + sum >= answer) return;
    if(cache[x][y][d] == -1 || cache[x][y][d] > sum) cache[x][y][d] = sum;
    // if(sum >= answer) return;
    if(x == n-1 && y == m -1) {
        answer = min(answer, sum);
        return;
    }
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[nx][ny] == 1) continue;
        if(check[nx][ny]) continue;
        check[nx][ny] = true;
        if(d == -1 || d == k) {
            if(cache[nx][ny][k] == -1 || cache[nx][ny][k] > sum + 100)
                go(nx, ny, k, sum + 100, board);
        }
        else {
            if(cache[nx][ny][k] == -1 || cache[nx][ny][k] > sum + 600)
                go(nx, ny, k, sum+600, board);
        }
        check[nx][ny] = false;
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    m = board[0].size();
    check[0][0] = true;
    answer = (n-1 + m -1) * 100 + (n-1) * (m-1) * 500;
    memset(cache, -1, sizeof(cache));
    go(0, 0, -1, 0, board);
    return answer;
}