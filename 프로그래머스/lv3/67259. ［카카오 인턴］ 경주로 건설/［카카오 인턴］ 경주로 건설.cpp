#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0}; // 하, 우, 상, 좌
int dy[] = {0, 1, 0, -1};
int answer = 2e9;
int n;
int cache[26][26][5]; // cache[x][y][d] : 현 위치가 (x, y) 이고, 이전 위치에서의 이동 방향이 d 일때의 최소 비용
// 이게 dp의 메모이제이션처럼 그냥 한번에 값이 기록됐다고 고정되는게 아니라, 새로운 값이 더 작으면 갱신됨.
// 더이상 탐색하지 않도록 하는 백트래킹 용도로 저장되는거.
// 따라서 값이 -1이 아니라고해서 바로 해당 값을 반환해버리면 안돼.
// int &ret = cache[x][y][d];
// if(ret != -1) return ret; 이라 하면, 안되는거야. 늦게 탐색했지만, 더 낮은 값이 갱신될 수 있기에.
// 이걸 dp 문제라고 봐야하나, dfs 문제라고 봐야하나 백트래킹 문제라고 봐야하나..
void go(int x, int y, int d, int sum, vector<vector<int>> &board) {
    if(x == n-1 && y == n -1) {
        answer = min(answer, sum);
        return;
    }
    int &ret = cache[x][y][d+1];
    if(ret != -1) {
        if(ret <= sum) return;
    }
    ret = sum;
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(board[nx][ny] == 1) continue;
        if(d == -1 || d == k) { // 현위치가 시작지점이거나, 이전이동방향과 동일한 방향으로 이동할시,
            // if(cache[nx][ny][k] == -1 || cache[nx][ny][k] > sum + 100)
                go(nx, ny, k, sum + 100, board);
        }
        else { // 이전이동방향과 다른 방향으로 이동을 하기에 코너 경주로를 건설해야 할 시,
            // if(cache[nx][ny][k] == -1 || cache[nx][ny][k] > sum + 600)
                go(nx, ny, k, sum + 600, board);
        }
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    memset(cache, -1, sizeof(cache));
    go(0, 0, -1, 0, board);
    return answer;
}