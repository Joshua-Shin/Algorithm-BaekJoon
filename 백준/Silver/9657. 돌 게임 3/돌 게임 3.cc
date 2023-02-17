#include <bits/stdc++.h>
using namespace std;
int n;
int cache[1001];
int dp(int n) {
    if(n==1 || n == 3 || n==4) return 0;
    if(n==2) return 1;
    int &ret = cache[n];
    if(ret != -1) return ret;
    return ret = !(dp(n-1) || dp(n-3) || dp(n-4));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(cache, -1, sizeof(cache));
    (dp(n)) ? cout << "CY" : cout << "SK";
}