#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int m, n;
bool check[102][102];
int cache[102][102];
int dfs(int x, int y) { // 행 열
    if(x == n-1 && y == m-1) return 1;
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    if(x+1 < n && !check[x+1][y]) ret += dfs(x+1, y) % mod;
    if(y+1 < m && !check[x][y+1]) ret += dfs(x, y+1) % mod;
    return ret % mod;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    ::m = m; ::n = n;
    for(auto p : puddles)
        check[p[1]-1][p[0]-1] = true;
    memset(cache, -1, sizeof(cache));
    return dfs(0, 0) % mod;
}