#include <bits/stdc++.h>
using namespace std;
int n, m, temp;
bool vip[41];
int cache[41][2];
int dfs(int idx, bool prevSwitch) {
    if(idx==n+1) return 1;
    int &ret = cache[idx][prevSwitch];
    if(ret != -1) return ret;
    ret = 0;
    if(vip[idx]) return ret += dfs(idx+1, false);
    if(prevSwitch) return ret += dfs(idx+1, false);
    else {
        if(idx != n && vip[idx+1]==false)
            ret += dfs(idx+1, true); 
        ret += dfs(idx+1, false);
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        cin >> temp;
        vip[temp] = true;
    }
    memset(cache, -1, sizeof(cache));
    cout << dfs(1, 0);
}