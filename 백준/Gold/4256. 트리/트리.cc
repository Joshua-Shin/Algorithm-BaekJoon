#include <bits/stdc++.h>
using namespace std;

int a[1001], b[1001];
int cur, n, tc;
vector<int> ans;
void go(int st, int en) {
    if(st >= en) return;
    int findIdx = st;
    for(int i = st; i < en; i++) {
        if(a[cur] == b[i]) {
            cur++;
            findIdx = i;
            break;
        }
    }
    go(st, findIdx);
    go(findIdx+1, en);
    ans.push_back(b[findIdx]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> tc;
    vector<vector<int>> ansans;
    while(tc--) {
        cin >> n;
        cur = 0;
        ans.clear();
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        go(0, n);
        ansans.push_back(ans);
    }
    for(auto ans: ansans) {
        for(auto x: ans) 
            cout << x << ' ';
        cout << '\n';
    }
}