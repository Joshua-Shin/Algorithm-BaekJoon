// https://www.algospot.com/judge/problem/read/JUMPGAME
#include <bits/stdc++.h>
using namespace std;
int tc, n, board[101][101];
vector<string> ans;
int cache[101][101];
bool dp(int x, int y) {
    if (x == n - 1 && y == n - 1) return true;
    int &ret = cache[x][y];
    if (ret != -1) return ret;
    int ny = y + board[x][y];
    int nx = x + board[x][y];
    bool result1 = false, result2 = false;
    if (0 <= ny && ny < n)
        result1 = dp(x, y + board[x][y]);
    if (0 <= nx && nx < n)
        result2 = dp(x + board[x][y], y);
    return ret = result1 || result2;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        memset(cache, -1, sizeof(cache));
        dp(0, 0) ? ans.push_back("YES") : ans.push_back("NO");
    }
    for (auto x : ans)
        cout << x << '\n';
}
