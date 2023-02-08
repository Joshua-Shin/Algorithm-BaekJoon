#include <bits/stdc++.h>
using namespace std;
tuple<int, int, int> edge[5001];
int p[101];
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
int kruskal (int n, int m, vector<vector<int>> &costs) { // 정점개수, 간선개수
    for(int i = 0; i < m; i++)
        edge[i] = {costs[i][2], costs[i][0], costs[i][1]};
    sort(edge, edge + m);
    int cnt = 0, answer = 0;
    for(int i = 0; i< m ; i++) {
        auto [cost, a, b] = edge[i];
        if(isSameParent(a, b)) continue;
        answer += cost;
        unionParent(a, b);
        if(++cnt == n-1) break;
    }
    return answer;
}
int solution(int n, vector<vector<int>> costs) {
    initiateParentTable(n);
    return kruskal(n, costs.size(), costs);
}