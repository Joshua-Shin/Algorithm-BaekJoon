#include <bits/stdc++.h>
using namespace std;
int go(vector<vector<int>> &board, vector<int> &q) {
    int x1 = q[0]-1, y1 = q[1]-1, x2 = q[2]-1, y2 = q[3]-1;
    vector<vector<int>> board2 = board;
    int ret = 1e9;
    for(int j = y1 + 1; j <= y2; j++) {
        board[x1][j] = board2[x1][j-1];
        ret = min(ret, board2[x1][j-1]);
    }
    for(int i = x1 + 1; i <= x2; i++) {
        board[i][y2] = board2[i-1][y2];
        ret = min(ret, board2[i-1][y2]);
    }
    for(int j = y2 -1; j >= y1; j--) {
        board[x2][j] = board2[x2][j+1];
        ret = min(ret, board2[x2][j+1]);
    }
    for(int i = x2 -1; i >= x1; i--) {
        board[i][y1] = board2[i+1][y1];
        ret = min(ret, board2[i+1][y1]);
    }
    return ret;
}
vector<int> solution(int n, int m, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(n, vector<int>(m, 0));
    int num = 1;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            board[i][j] = num++;

    for(auto q: queries) {
        answer.push_back(go(board, q));
        // 검증 맞는디?
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         if(board[i][j] < 10) cout << '0' << board[i][j] << ' ';
        //         else cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    return answer;
}