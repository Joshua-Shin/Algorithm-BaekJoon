#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int cache[60001];
int dp(int x) {
    if (x == 0 || x == 1 || x  == 2) return x;
    int &ret = cache[x];
    if (ret != -1) return ret;
    return ret = ((dp(x - 1) % mod) + (dp(x - 2) % mod)) % mod;
}
int solution(int n) {
    memset(cache, -1, sizeof(cache));
    return dp(n);
}