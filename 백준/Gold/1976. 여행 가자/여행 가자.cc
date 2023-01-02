#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[205];
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
    for(int i = 1; i<=n; i++) p[i] = i;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {  
            int temp;
            cin >> temp;
            if(temp) unionParent(i, j);
        }
    }
    vector<int> path(m);
    for(int i = 0; i<m; i++)
        cin >> path[i];
    string ans = "YES";
    for(int i = 1; i<m; i++) {
        if(!isSameParent(path[i-1], path[i])) {
            ans = "NO";
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}