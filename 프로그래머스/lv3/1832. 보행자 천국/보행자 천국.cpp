#include <bits/stdc++.h>
using namespace std;
int MOD = 20170805;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
typedef long long ll;
int n, m;
int dx[2];
int dy[2];
ll cache[501][501][2];
ll dfs(int x, int y, int dir, vector<vector<int>> &board) {
    if(x == n - 1 && y == m - 1) return 1;
    ll &ret = cache[x][y][dir];
    if(ret != -1) return ret;
    ret = 0;
    for(int k = 0; k < 2; k++) {
        // 현재 밟고 있는 판이 0 일때, 1일때 2 일때.
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(board[x][y] == 0) {
            if(board[nx][ny] != 1)
                ret += dfs(nx, ny, k, board) % MOD;
        } else if (board[x][y] == 2) { // 직진만 가능
            if(board[nx][ny] != 1)
                if((x==0 && y==0) || dir == k)
                    ret += dfs(nx, ny, k, board) % MOD;
        }
    }
    return ret %= MOD;
}
int solution(int m, int n, vector<vector<int>> city_map) {
    ::n = m;
    ::m = n;
    dx[0] = 0; dx[1] = 1;
    dy[0] = 1; dy[1] = 0;
    memset(cache, -1, sizeof(cache));
    return dfs(0, 0, 0, city_map);
}