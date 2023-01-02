#include <bits/stdc++.h>
using namespace std;
int p[500001];
int n, m;
int getParent(int x) {
    if (p[x] == x) return x;
    return p[x] = getParent(p[x]);
}
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x < y) p[y] = x;
    else p[x] = y;
}
bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}
void initiateParentTable(int n) {
    for (int i = 1; i < n; i++)
        p[i] = i;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    initiateParentTable(n);
    int ans = 0;
    vector<pair<int, int>> input;
    int cnt = 0;
    while(m--) {
        int a, b;
        cin >> a >> b;
        input.push_back({a, b});
    }
    for(auto e: input) {
        if(isSameParent(e.first, e.second)) {
            ans = ++cnt;
            break;
        }
        unionParent(e.first, e.second);
        cnt++;
    }
    cout << ans << '\n';
    return 0;
}