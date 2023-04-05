#include <bits/stdc++.h>
using namespace std;
int board[1001][1001];
void go(int x, int y, int h, int n) { // 시작 좌표 x y, 높이, 시작 값 
    if(h == 0) return;
    if(h == 1) {
        board[x][y] = n;
        return;
    }
    if(h == 2) {
        board[x][y] = n;
        board[x+1][y] = n +1;
        board[x+1][y+1] = n + 2;
        return;
    }
    int value = n;
    int nx = x, ny = y;
    while(1) {
        board[nx++][y] = value++;
        if(nx == x + h) {
            nx--;
            ny++;
            break;
        }
    }
    while(1) {
        board[nx][ny++] = value++;
        if(ny == y + h) {
            ny -= 2;
            nx--;
            break;
        }
    }
    while(1) {
        board[nx--][ny--] = value++;
        if(nx == x && ny == y) {
            nx += 2;
            ny++;
            break;
        }
    }
    go(nx, ny, h-3, value);
}
vector<int> solution(int n) {
    vector<int> answer;
    go(0, 0, n, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            answer.push_back(board[i][j]);
        }
    }
    return answer;
}