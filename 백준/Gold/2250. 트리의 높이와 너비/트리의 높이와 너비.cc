#include <bits/stdc++.h>
using namespace std;
int n;
int lc[10001];
int rc[10001]; // rc[x] = x의 오른쪽 자식 노드
int row[10001]; // row[x] = 정점 x의 행 값
int col[10001]; // col[x] = 정점 x의 열 값
int maxLc[10001]; // maxLc[x] = 레벨이 x인 노드 중 왼쪽 노드 번호
int maxRc[10001];
int root;
int p[10001];
int bfs(int x) {
    int maxLevel = 1;
    queue<int> q;
    row[x] = 1;
    maxLc[row[x]] = x;
    maxRc[row[x]] = x;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        maxLevel = max(maxLevel, row[x]);
        // cout << "x: " << x << '\n';
        // cout << "row[x]: " << row[x] << '\n';
        // cout << "maxLc[row[x]]: " << maxLc[row[x]] << '\n';
        // cout << "col[maxLc[row[x]]]: " << col[maxLc[row[x]]] << '\n';
        if(col[x] < col[maxLc[row[x]]] || maxLc[row[x]]==0) maxLc[row[x]] = x;
        if(col[x] > col[maxRc[row[x]]]) maxRc[row[x]] = x;
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
    col[x] = colValue++;
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
        p[b] = a;
        p[c] = a;
    }
    findRoot(1);
    inOrder(root);
    int maxLevel = bfs(root);
    int answerWidth = 1;
    int answerLevel = 1;
    for(int i = 1; i<=maxLevel; i++) {
        int left = maxLc[i];
        int right = maxRc[i];
        int width = col[right] - col[left] + 1;
        if(width > answerWidth) {
            answerWidth = width;
            answerLevel = row[left];
        }
    }
    cout << answerLevel << ' ' << answerWidth << '\n';
    return 0;
}