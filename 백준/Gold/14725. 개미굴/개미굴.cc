#include <bits/stdc++.h>
using namespace std;
const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];
int root = 1;
int unused = 2; // 정점번호 값. insert 할때 문자 하나 하나 추가할때마다 ++ 됨.
void insert(vector<string> &v) {
    int cur = root;
    for(auto s: v) {
        if(!nxt[cur][s])
            nxt[cur][s] = unused++;
        cur = nxt[cur][s];
    }
}
void dfs(int cur, int d) {
    for(auto nx: nxt[cur]) {
        string level;
        for(int i = 0; i<d; i++) level += "--";
        cout << level << nx.first << '\n';
        dfs(nx.second, d + 1);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<string> inputStr(m);
        for (int i = 0; i < m; i++) cin >> inputStr[i];
        insert(inputStr);
    }
    dfs(1, 0);
}