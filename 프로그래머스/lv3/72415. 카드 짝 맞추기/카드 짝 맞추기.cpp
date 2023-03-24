#include <bits/stdc++.h>
using namespace std;
int minCost = 1e9;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int go(string &board, int start, int end) {
    int dist[16];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        start = q.front();
        if(start == end) return dist[start];
        q.pop();
        int x = start / 4;
        int y = start % 4;
        for(int k = 0; k < 4; k++) {
            int nx = x, ny = y;
            int nCur;
            while(1) {
                nx += dx[k];
                ny += dy[k];
                if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                    nx -= dx[k];
                    ny -= dy[k];
                    break;
                }
                nCur = nx * 4 + ny;
                if(board[nCur] != '0') break;
            }
            nCur = nx * 4 + ny;
            if(dist[nCur] != -1) continue;
            dist[nCur] = dist[start] + 1;
            q.push(nCur);
        }
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            int nCur = nx * 4 + ny;
            if(dist[nCur] != -1) continue;
            dist[nCur] = dist[start] + 1;
            q.push(nCur);
        }
    }
    return dist[end];
}
int solution(vector<vector<int>> board, int r, int c) {
    string strBoard;
    vector<int> v;
    vector<int> card[7];
    for(int i = 0; i < 4; i++) 
        for(int j = 0; j< 4; j++) {
            strBoard += to_string(board[i][j]);
            if(board[i][j] != 0) card[board[i][j]].push_back(i*4 + j);
        }
    for(int i = 1; i <= 6; i++) {
        if(!card[i].empty()) v.push_back(i);
    }
    int n = v.size(); // 카드 종류 개수
    do {
        string strBoard2 = strBoard;
        int cur = r * 4 + c;
        int d[6][2];
        d[0][0] = go(strBoard2, cur, card[v[0]][0]) + go(strBoard2, card[v[0]][0], card[v[0]][1]);
        d[0][1] = go(strBoard2, cur, card[v[0]][1]) + go(strBoard2, card[v[0]][1], card[v[0]][0]);
        strBoard2[card[v[0]][0]] = '0';
        strBoard2[card[v[0]][1]] = '0';
        for(int i = 1; i < n; i++) {
            d[i][0] = min(d[i-1][0] + go(strBoard2, card[v[i-1]][1], card[v[i]][0]),
                            d[i-1][1] + go(strBoard2, card[v[i-1]][0], card[v[i]][0])) 
                            + go(strBoard2, card[v[i]][0], card[v[i]][1]);
            d[i][1] = min(d[i-1][0] + go(strBoard2, card[v[i-1]][1], card[v[i]][1]),
                            d[i-1][1] + go(strBoard2, card[v[i-1]][0], card[v[i]][1])) 
                            + go(strBoard2, card[v[i]][1], card[v[i]][0]);
            strBoard2[card[v[i]][0]] = '0';
            strBoard2[card[v[i]][1]] = '0';
        }
        minCost = min({minCost, d[n-1][0], d[n-1][1]});
    } while (next_permutation(v.begin(), v.end()));
    return minCost + n * 2;
}