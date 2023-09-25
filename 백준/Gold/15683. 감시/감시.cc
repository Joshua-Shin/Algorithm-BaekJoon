#include <bits/stdc++.h>
using namespace std;
// 0 빈칸, 1~5 cctv, 6 벽, -1을 살펴본 공간,
// see 0 1 2 3 동서남북// 4 이상 값은 0123으로 수정.
int n, m;
int answer;
vector<vector<int>> v; // i, j, value
void see(int dir, vector<vector<int>> &board, int x, int y) {
    if(dir >= 4) dir %= 4;
    if(dir == 0 ) {
        for(int j = y +1; j<m; j++) {
            if(board[x][j] == 6) break;
            if(board[x][j]==0) board[x][j] = -1;
        }
    }
    else if(dir == 1) {
        for(int i = x -1 ; i >= 0; i--) {
            if(board[i][y] == 6) break;
            if(board[i][y]==0) board[i][y] = -1;
        }
    }
    else if(dir == 2) {
        for(int j = y -1; j >= 0; j--) {
            if(board[x][j] == 6) break;
            if(board[x][j]==0) board[x][j] = -1;
        }
    }
    else if(dir==3) {
        for(int i = x +1 ; i < n; i++) {
            if(board[i][y] == 6) break;
            if(board[i][y]==0) board[i][y] = -1;
        }
    }
}

void go(int idx, vector<vector<int>> board) {
    if(idx == v.size()) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if(board[i][j] == 0) count++;
        }
        answer = min(answer, count);
        return;
    }

    if(v[idx][2]==1) {
        for(int k = 0; k< 4; k++) {
            vector<vector<int>> board2 = board;
            see(k, board2, v[idx][0], v[idx][1]);
            go(idx +1, board2);
        }
    } 
    else if(v[idx][2]==2) {
        for(int k = 0; k< 2; k++) {
            vector<vector<int>> board2 = board;
            see(k, board2, v[idx][0], v[idx][1]);
            see(k + 2, board2, v[idx][0], v[idx][1]);
            go(idx +1, board2);
        }
    }
    else if(v[idx][2]==3) {
        for(int k = 0; k < 4; k++) {
            vector<vector<int>> board2 = board;
            see(k, board2, v[idx][0], v[idx][1]);
            see(k + 1, board2, v[idx][0], v[idx][1]);
            go(idx +1, board2);
        }
    }
    else if(v[idx][2]==4) {
        for(int k = 0; k < 4; k++) {
            vector<vector<int>> board2 = board;
            see(k, board2, v[idx][0], v[idx][1]);
            see(k + 1, board2, v[idx][0], v[idx][1]);
            see(k + 2, board2, v[idx][0], v[idx][1]);
            go(idx +1, board2);
        }
    }
    else if(v[idx][2]==5) {
        vector<vector<int>> board2 = board;
        for(int k = 0; k < 4; k++) 
            see(k, board2, v[idx][0], v[idx][1]);
        go(idx +1, board2);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    answer = n * m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <=5) v.push_back({i, j, board[i][j]}); 
        }
    
    go(0, board);
    cout << answer << '\n';
    return 0;
}