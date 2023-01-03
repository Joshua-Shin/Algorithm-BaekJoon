#include <bits/stdc++.h>
using namespace std;
int p[200001];
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
tuple<int, int, int> edge[200005];
int kruskal (int n, int m) { // 정점개수, 간선개수
    int sumCost = 0;
    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
        sumCost += cost;
    }
    sort(edge, edge + m);
    int cnt = 0, answer = 0;
    for(int i = 0; i< m ; i++) {
        auto [cost, a, b] = edge[i];
        if(isSameParent(a, b)) continue;
        answer += cost;
        unionParent(a, b);
        if(++cnt == n-1) break;
    }
    return sumCost - answer;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    while(!(n==0 && m ==0)) {
        memset(p, 0, sizeof(p));
        memset(edge, 0, sizeof(edge));
        initiateParentTable(n-1);
        ans.push_back(kruskal(n, m));
        cin >> n >> m;
    }
    for(auto x: ans) cout << x << '\n';
    return 0;
}