#include <bits/stdc++.h>
using namespace std;
int cache[100002][5];
int dfs(int x, int y, vector<vector<int>> &land) {
    if (x == land.size()-1) return 0;
    int &ret = cache[x+1][y+1];
    if (ret != -1) return ret;
    for (int i = 0; i < 4; i++) {
        if (i == y) continue;
        ret = max(ret, dfs(x + 1, i, land) + land[x + 1][i]);
    }
    return ret;
}
int solution(vector<vector<int>> land) {
    memset(cache, -1, sizeof(cache));
    return dfs(-1, -1, land);
}