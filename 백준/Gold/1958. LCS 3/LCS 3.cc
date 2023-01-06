#include <bits/stdc++.h>
using namespace std;
string a, b, c;
int cache[101][101][101];
int go(int cur1, int cur2, int cur3) {
    if(cur1 == a.size() || cur2 == b.size() || cur3 == c.size()) return 0;
    int &ret = cache[cur1][cur2][cur3];
    if(ret != -1) return ret;
    if(a[cur1] == b[cur2] && b[cur2] == c[cur3]) {
        ret = go(cur1+1, cur2+1, cur3+1) + 1;
    } else {
        ret = max({go(cur1+1, cur2, cur3), go(cur1, cur2+1, cur3), go(cur1, cur2, cur3+1)});
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b >> c;
    memset(cache, -1, sizeof(cache));
    cout << go(0, 0, 0) << '\n';
    return 0;
}