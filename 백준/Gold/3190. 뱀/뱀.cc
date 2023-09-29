#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int board[101][101];
void print_all() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    unordered_map<int, char> oper;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1; // 사과
    }
    cin >> l;
    // dir = 'D' 현 위치에서 왼쪽 회전, 'C' 현 위치에서 오른쪽 회전
    for(int i = 0; i < l; i++) {
        int t;
        char dir;
        cin >> t >> dir;
        oper[t] = dir;
    }
    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    board[0][0] = 2;
    int nx = 0, ny = 0;
    for(int i = 0, k = 0; ; i++) {
        // print_all();
        if(oper.find(i) != oper.end()) {
            if(oper[i] == 'L') {
                k++;
                if(k == 4) k = 0;
            }
            else {
                k--;
                if(k == -1) k = 3;
            }
        }
        nx = nx + dx[k];
        ny = ny + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {
            cout << i + 1 << '\n';
            return 0;
        }
        if(board[nx][ny] == 0) {
            board[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        dq.push_front({nx, ny});
        board[nx][ny] = 2;
    }
    return 0;
}