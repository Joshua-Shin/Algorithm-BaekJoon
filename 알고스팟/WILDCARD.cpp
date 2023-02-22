// https://www.algospot.com/judge/problem/read/WILDCARD
#include <bits/stdc++.h>
using namespace std;
int tc, n;
string W, S;
vector<vector<string>> ans;
int cache[101][101];
int dfs(int w, int s) {
    if(w == W.size() && s == S.size()) return 1;
    int &ret = cache[w][s];
    if(ret != -1) return ret;
    if(s < S.size() && w < W.size()) {
        if(W[w] == '?' || W[w] == S[s]) return ret = dfs(w+1, s+1);
        if(W[w] == '*') return ret = dfs(w+1, s) || dfs(w, s+1);
    }
    if(s == S.size() && W[w] == '*')
        return ret = dfs(w+1, s);
    return ret = 0;
}
int main() {
    cin >> tc;
    while(tc--) {
        cin >> W >> n;
        vector<string> subAns;
        for (int i = 0; i < n; i++) {
            cin >> S;
            memset(cache, -1, sizeof(cache));
            if(dfs(0, 0)) subAns.push_back(S);
        }
        sort(subAns.begin(), subAns.end());
        ans.push_back(subAns);
    }
    for(auto v: ans)
        for(auto x: v)
            cout << x << '\n';
}
