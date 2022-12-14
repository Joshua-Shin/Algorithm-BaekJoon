#include <bits/stdc++.h>
using namespace std;
int lc[27]; // lc[x] = x 노드의 왼쪽 자식노드 값.
int rc[27]; // rc[x] = x 노드의 오른쪽 자식 노드 값.
void preOrder(int x) {
    cout << char(x - 1 + 'A');
    if(lc[x]) preOrder(lc[x]);
    if(rc[x]) preOrder(rc[x]);
}
void inOrder(int x) {
    if(lc[x]) inOrder(lc[x]);
    cout << char(x - 1 + 'A');
    if(rc[x]) inOrder(rc[x]);
}
void postOrder(int x) {
    if(lc[x]) postOrder(lc[x]);
    if(rc[x]) postOrder(rc[x]);
    cout << char(x - 1 + 'A');
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if(b!='.') lc[a - 'A' + 1] = b - 'A' + 1;
        if(c!='.') rc[a - 'A' + 1] = c - 'A' + 1;
    }

    preOrder(1);
    cout << '\n';
    inOrder(1);
    cout << '\n';
    postOrder(1);
    cout << '\n';

    return 0;
}