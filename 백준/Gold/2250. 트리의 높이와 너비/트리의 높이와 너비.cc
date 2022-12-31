#include <bits/stdc++.h>
using namespace std;
int n;
int p[10001];
int lc[10001], rc[10001]; // rc[x] = x의 오른쪽 자식 노드
int row[10001], col[10001]; // col[x] = 정점 x의 열 값
pair<int, int> mostLRCol[10001]; // 높이가 x일때, 가장 왼쪽 열값, 가장 오른쪽 열값
int root;
int bfs(int x) {
    int maxLevel = 1;
    queue<int> q;
    row[x] = 1;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        maxLevel = max(maxLevel, row[x]);
        q.pop();
        if(lc[x]!=-1){
            row[lc[x]] = row[x] + 1;
            q.push(lc[x]);
        }
        if(rc[x]!=-1){
            row[rc[x]] = row[x] + 1;
            q.push(rc[x]);
        }
    }
    return maxLevel;
}
int colValue = 1;
void inOrder(int x) {
    if(lc[x]!=-1) inOrder(lc[x]);
    colValue++;
    auto &[lCol, rCol] = mostLRCol[row[x]];
    if(!lCol || colValue < lCol) lCol = colValue;
    if(!rCol || colValue > rCol) rCol = colValue;
    if(rc[x]!=-1) inOrder(rc[x]);
}
void findRoot(int x) {
    if(p[x]==0) {
        root = x;
        return;
    }
    findRoot(p[x]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
        if(b!=-1)p[b] = a;
        if(c!=-1)p[c] = a;
    }
    findRoot(1);
    int maxLevel = bfs(root);
    inOrder(root);
    int answerWidth = 1, answerLevel = 1;
    for(int i = 1; i<=maxLevel; i++) {
        int width = mostLRCol[i].second - mostLRCol[i].first + 1;
        if(width > answerWidth) {
            answerWidth = width;
            answerLevel = i;
        }
    }
    cout << answerLevel << ' ' << answerWidth << '\n';
    return 0;
}