#include <bits/stdc++.h>
using namespace std;
int p[1001];
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
// tuple<int, int, int> edge[1000005];
vector<tuple<double, int, int>> edge;
double kruskal (int n) { // 정점개수, 간선개수
    int cnt = 0;
    double answer = 0;
    for(auto e: edge) {
        auto [cost, a, b] = e;
        if(isSameParent(a, b)) continue;
        answer += cost;
        unionParent(a, b);
        if(++cnt == n-1) break;
    }
    return answer;
}
double calCost(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed;
    cout.precision(2);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i = 0; i < v.size()-1; i++) {
        for(int j = i + 1; j < v.size(); j++) {
            edge.push_back({calCost(v[i].first, v[i].second, v[j].first, v[j].second), i, j});
        }
    }
    sort(edge.begin(), edge.end());
    initiateParentTable(n-1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        unionParent(a-1, b-1);
    }
    cout << kruskal(n) << '\n';
    return 0;
}