#include <bits/stdc++.h>
using namespace std;
int n;
int lc[10001], rc[10001];
int p[10001];
int root;
int maxLevel = 0;
int colValue = 0;
pair<int, int> colLR[10001]; // colLR[x] : 높이가 x일떄 가장 왼쪽 노드의 열값과 가장 오른쪽 노드의 열값
void inOrder(int x, int d) {
    if(d > maxLevel) maxLevel = d;
    if(lc[x]!=-1) inOrder(lc[x], d+1);
    auto &[leftCol, rightCol] = colLR[d];
    colValue++;
    if(!leftCol || leftCol > colValue) leftCol = colValue;
    if(!rightCol || rightCol < colValue) rightCol = colValue;
    if(rc[x]!=-1) inOrder(rc[x], d+1);
}
int findRoot(int x) {
    if(p[x]==0) return x;
    return findRoot(p[x]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b; rc[a] = c;
        if(b!=-1) p[b] = a;
        if(c!=-1) p[c] = a;
    }
    root = findRoot(1);
    inOrder(root, 1);
    int ansLevel = 1, ansWidth = 1;
    for(int i = 1; i <= maxLevel; i++) {
        int width = colLR[i].second - colLR[i].first + 1;
        if(ansWidth < width) {
            ansWidth = width;
            ansLevel = i;
        }
    }
    cout << ansLevel << ' ' << ansWidth << '\n';
    return 0;
}