#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[1000005];
int getParent(int x) {
    if(p[x]==x) return x;
    return p[x] = getParent(p[x]);
}
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if(x < y) p[y] = x;
    else p[x] = y;
}
bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<=n; i++) 
        p[i] = i;
    vector <string> ans;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==0) unionParent(b, c);
        if(a==1) ans.push_back(isSameParent(b, c) ? "YES" : "NO");
    }
    for(auto x: ans)
        cout << x << '\n';
    return 0;
}