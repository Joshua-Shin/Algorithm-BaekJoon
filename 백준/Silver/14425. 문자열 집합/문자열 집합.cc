#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    map<string, int> s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        s[temp]++;
    }
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        string temp;
        cin >> temp;
        if(s[temp]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}