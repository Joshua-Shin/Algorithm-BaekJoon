#include <bits/stdc++.h>
using namespace std;
int n;
int lc[27], rc[27];
string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int c2i(char c) {
    return c - 'A' + 1;
}
void preOrder(int cur) {
    cout << dic[cur - 1];
    if(lc[cur]) preOrder(lc[cur]);
    if(rc[cur]) preOrder(rc[cur]);
}
void inOrder(int cur) {
    if(lc[cur]) inOrder(lc[cur]);
    cout << dic[cur - 1];
    if(rc[cur]) inOrder(rc[cur]);
}
void postOrder(int cur) {
    if(lc[cur]) postOrder(lc[cur]);
    if(rc[cur]) postOrder(rc[cur]);
    cout << dic[cur - 1];
}
int main() {
    cin >> n;
    for(int i = 0; i<n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        if(b != '.') lc[c2i(a)] = c2i(b);
        if(c != '.') rc[c2i(a)] = c2i(c);
    }    
    preOrder(1);
    cout << '\n';
    inOrder(1);
    cout << '\n';
    postOrder(1);
    cout << '\n';
}


