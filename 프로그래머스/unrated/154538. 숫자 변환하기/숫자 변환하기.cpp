#include <bits/stdc++.h>
using namespace std;
int cache[1000001];
int y, n;
int dfs(int x) {
    if(x == y) return 0;
    int &ret = cache[x];
    if(ret != -1) return ret;
    ret = 1e9;
    if(x + n <= y) ret = min(ret, dfs(x + n) + 1);
    if(x * 2 <= y) ret = min(ret, dfs(x * 2) + 1);
    if(x * 3 <= y) ret = min(ret, dfs(x * 3) + 1);
    return ret;
}
int solution(int x, int y, int n) {
    memset(cache, -1, sizeof(cache));
    ::y = y; ::n = n;
    int ans = dfs(x);
    return ans >= 1e9 ? -1 : ans;
}