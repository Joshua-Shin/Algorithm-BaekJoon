#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> coin;
int cache[21][20001];
int go(int cur, int sum) {
    if(cur == coin.size()) {
        if(sum == m) return 1;
        return 0;
    }
    int & ret = cache[cur][sum];
    if(ret!=-1) return ret;
    ret = 0;
    int money = m - sum;
    int maxCnt = money / coin[cur];
    for(int k = 0; k<= maxCnt; k++)
        ret += go(cur+1, sum + coin[cur]*k);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    vector<int> ans;
    while(tc--) {
        cin >> n;
        coin.clear();
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            coin.push_back(temp);
        }
        cin >> m;
        ans.push_back(go(0, 0));
    }
    for(auto x: ans)
        cout << x << '\n';
    return 0;
}