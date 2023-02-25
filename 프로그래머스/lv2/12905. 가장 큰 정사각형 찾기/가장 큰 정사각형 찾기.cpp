#include <bits/stdc++.h>
using namespace std;
int cache[1001][1001];
int dfs(int x, int y, vector<vector<int>> &board) {
    if(x == 0 || y == 0) return board[x][y];
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    if(!board[x][y]) return ret = 0;
    ret = min({dfs(x-1, y, board), dfs(x, y-1, board), dfs(x-1, y-1, board)}) + 1;
    return ret;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< m ; j++) {
            answer = max(answer, dfs(i, j, board));
        }
    }
    return answer * answer;
}