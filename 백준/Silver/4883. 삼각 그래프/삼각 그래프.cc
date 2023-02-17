#include <bits/stdc++.h>
using namespace std;
int n;
int board[100'001][3];
int cache[100'001][3];
int dp(int x, int y) {
    if(x==n-1) {
        if(y==0) return board[x][y] + board[x][y+1];
        if(y==1) return board[x][y];
        return 1e9;
    }
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    if(y==0) return ret = board[x][y] + min({dp(x+1, y), dp(x+1, y+1), dp(x, y+1)});
    if(y==1) return ret = board[x][y] + min({dp(x+1, y), dp(x+1, y+1), dp(x, y+1), dp(x+1, y-1)});
    return ret = board[x][y] + min({dp(x+1, y), dp(x+1, y-1)});
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int cnt = 1;
    while(1) {
        cin >> n;
        if(!n) return 0;
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 3; j++) 
                cin >> board[i][j];
        cout << cnt++ << ". " << dp(0, 1) << '\n';
    }
}