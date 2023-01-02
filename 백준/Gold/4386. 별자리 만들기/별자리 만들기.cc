#include <bits/stdc++.h>
using namespace std;
int n;
tuple<double, int, int> edge[10005];
int p[100001];
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
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
double calCost(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    initiateParentTable(n-1);
    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int m = 0;
    for(int i = 0; i < v.size()-1; i++) {
        for(int j = i+1; j < v.size(); j++) {
            edge[m++] = {calCost(v[i].first, v[i].second, v[j].first, v[j].second), i, j};
        }
    }
    m++;
    sort(edge, edge+m);
    int cnt = 0;
    double ans = 0;
    for(int i = 0; i<m; i++) {
        auto [cost, a, b] = edge[i];
        if(isSameParent(a, b)) continue;
        unionParent(a, b);
        ans += cost;
        if(++cnt == n-1) break;
    }
    cout << ans << '\n';
    return 0;
}