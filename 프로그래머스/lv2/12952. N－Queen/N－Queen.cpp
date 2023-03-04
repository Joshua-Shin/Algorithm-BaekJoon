#include <bits/stdc++.h>
using namespace std;
int n;
bool check[13][13];
int dx[] = {-1, -1, -1};
int dy[] = {1, 0, -1};
bool isOk(int x, int y) {
    for(int k = 0; k < 3; k++) {
        int nx = x;
        int ny = y;
        while(1) {
            nx += dx[k];
            ny += dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if(check[nx][ny]) return false;
        }
    }
    return true;
}
int go(int x) { // 행
    if(x == n) return 1;
    int ret = 0;
    for(int i = 0; i < n; i++) { // 열
        if(check[x][i]) continue;
        if(!isOk(x, i)) continue;
        check[x][i] = true;
        ret += go(x + 1);
        check[x][i] = false;
    }
    return ret;
}
int solution(int n) {
    ::n = n;
    return go(0);    
}