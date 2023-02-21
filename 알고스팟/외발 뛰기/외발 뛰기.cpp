#include <bits/stdc++.h>
using namespace std;
int tc, n, board[101][101];
vector<string> ans;
int cache[101][101];
bool dp(int x, int y) {
    if (x == n - 1 && y == n - 1) return true;
    if (x >= n || y >= n) return false;
    int &ret = cache[x][y];
    if (ret != -1) return ret;
    return ret = dp(x, y + board[x][y]) || dp(x + board[x][y], y);
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
