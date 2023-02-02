#include <bits/stdc++.h>
using namespace std;
const int mod = 1234567;
int cache[100001];
int dp(int n) {
    if(n == 0 || n == 1) return n;
    int &ret = cache[n];
    if(ret != -1) return ret;
    return ret = (dp(n-1) + dp(n-2)) % mod;
}
int solution(int n) {
    memset(cache, -1, sizeof(cache));
    return dp(n);
}