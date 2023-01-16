#include <bits/stdc++.h>
using namespace std;
string a, b;
string ans;
int cur;
void go(int st, int en) {
    if(st >= en) return;
    int findIdx = st;
    for(int i = st; i< en; i++) {
        if(b[i] == a[cur]) {
            findIdx = i;
            cur++;
            break;
        }
    }
    go(st, findIdx);
    go(findIdx+1, en);
    ans += b[findIdx];
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> a >> b) {
        ans.clear();
        cur = 0;
        go(0, a.size());
        cout << ans << '\n';
    }
}