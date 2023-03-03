#include <bits/stdc++.h>
using namespace std;
int answer;
int n;
bool check[15][15];
int dx[] = {-1, -1, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isOk(int x, int y) {
    for(int k = 0; k < 4; k++) {
        int nx = x, ny = y;
        while(1) {
            nx += dx[k];
            ny += dy[k];
            if(nx < 0 || n <= nx || ny < 0 || n <= ny) break;
            if(check[nx][ny]) return false;
        }
    }
    return true;
}
void dfs(int x) { // 행
    if(x == n) {
        answer++;
        return;
    }
    for(int i = 0; i < n; i++) { // 열
        if(check[x][i] || !isOk(x, i)) continue;
        check[x][i] = true;
        dfs(x + 1);
        check[x][i] = false;
    }
}
int solution(int n) {
    ::n = n;
    dfs(0);
    return answer;
}
int main() {
    cout << solution(4);
}