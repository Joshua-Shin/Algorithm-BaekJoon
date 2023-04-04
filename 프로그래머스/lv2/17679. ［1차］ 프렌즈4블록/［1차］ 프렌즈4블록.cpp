#include <bits/stdc++.h>
using namespace std;
int zeroCounter(vector<string> board) {
    int ret = 0;
    for (int i = 0; i < board.size(); i++) 
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] == '0') ret++;
    return ret;
}
bool del(vector<string> &board) { // 삭제할 애들 체크하고, 0으로 바꿔주고
    vector<pair<int, int>> v;
    for(int i = 0; i<board.size()-1; i++) {
        for(int j = 0; j < board[i].size()-1; j++) {
            char c = board[i][j];
            if(c == '0') continue;
            if(board[i+1][j] == c && board[i][j+1] == c && board[i+1][j+1] == c) {
                v.push_back({i, j});
                v.push_back({i, j+1});
                v.push_back({i+1, j});
                v.push_back({i+1, j+1});
            }
        }
    }
    for(auto e: v) {
        board[e.first][e.second] = '0';
    }
    return v.size();
}
void down(vector<string> &board) {
    for(int i = board.size()-1; i > 0; i--) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == '0') {
                int row = i;
                while(1) {
                    row--;
                    if(row==-1 || board[row][j]!= '0') break;
                }
                if(row == -1) continue;
                swap(board[row][j], board[i][j]);
            }
        }
    }
}
int solution(int m, int n, vector<string> board) {
    // 삭제할때마다 개수 카운트할 필요는 없고
    // 삭제할 애들 쭉 잡아낸다음에 '0' 으로 바꾸고,
    // 아래로 떨궈주는 시뮬레이션만 잘 만드는게 핵심이네
    // 시뮬레이션 끝나면, 남아있는 '0'의 개수 카운트해서, 전체 판 사이즈에서 빼주면 됨.
    // 이렇게 해보고 틀리게 나오면, 아마 판이 완전히 꽉 채운 상태가 초기값으로 주어지지 않은 경우일 수도!
    while(1) {
        bool flag = del(board);
        if(flag == false) break;
        down(board);
    }
    return zeroCounter(board);
}