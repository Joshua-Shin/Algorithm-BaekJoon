#include <bits/stdc++.h>
using namespace std;
map<string, string> p;
map<string, int> cnt;
string getParent(string x) {
    if(p[x] == x) return x;
    return p[x] = getParent(p[x]);
}
void unionParent(string x, string y) {
    x = getParent(x);
    y = getParent(y);
    if(x < y) {
        p[y] = x;
        cnt[x] += cnt[y];
    }
    else {
        p[x] = y;
        cnt[y] += cnt[x];
    }
}
bool isSameParent(string x, string y) {
    return getParent(x) == getParent(y);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    vector<int> ans;
    while(tc--) {
        p.clear();
        int f;
        cin >> f;
        vector<string> v;
        vector<pair<string, string>> input;
        while(f--) {
            string a, b;
            cin >> a >> b;
            v.push_back(a);
            v.push_back(b);
            input.push_back({a, b});
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(auto x: v) {
            p[x] = x;
            cnt[x] = 1;
        }
        for(auto e: input) {
            if(!isSameParent(e.first, e.second))
                unionParent(e.first, e.second);
            ans.push_back(max(cnt[p[e.first]], cnt[p[e.second]]));
        }
    }
    for(auto x: ans)
        cout << x << '\n';
    return 0;
}