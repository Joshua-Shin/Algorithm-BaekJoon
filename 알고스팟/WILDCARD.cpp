// https://www.algospot.com/judge/problem/read/WILDCARD
#include <bits/stdc++.h>
using namespace std;
int tc, n;
string W, S;
vector<string> ans;
vector<vector<string>> totalAns;
int cache[101][101];
int dfs(int w, int s) {
    if(w == W.size() && s == S.size()) return 1;
    int &ret = cache[w][s];
    if(ret != -1) return ret;
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
        return ret = dfs(w+1, s+1);
    if(W[w] == '*') {
        if(dfs(w+1, s) || (s < S.size() && dfs(w, s+1)))
            return ret = 1;
    }
    return ret = 0;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> tc;
    while(tc--) {
        cin >> W;
        cin >> n;
        ans.clear();
        for (int i = 0; i < n; i++) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(dfs(0, 0)) ans.push_back(S);
        }
        sort(ans.begin(), ans.end());
        totalAns.push_back(ans);
    }
    for(auto v: totalAns)
        for(auto x: v)
            cout << x << '\n';
}
