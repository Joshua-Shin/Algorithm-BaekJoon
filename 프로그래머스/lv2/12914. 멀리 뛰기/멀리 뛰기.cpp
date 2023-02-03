#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 1234567;
typedef long long ll;
ll cache[2001];
ll dfs(int d) {
    if(d==n) return 1;
    if(d>n) return 0;
    ll &ret = cache[d];
    if(ret != -1) return ret;
    return ret = dfs(d + 1) % mod + dfs(d+2) % mod;
}
long long solution(int n) {
    ::n = n;
    memset(cache, -1, sizeof(cache));
    return dfs(0) % mod;
}