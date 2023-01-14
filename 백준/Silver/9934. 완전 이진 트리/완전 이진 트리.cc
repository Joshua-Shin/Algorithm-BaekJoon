#include <bits/stdc++.h>
using namespace std;
int n, level;
int arr[2000];
vector<int> ans[12]; // ans[x]: x 층일떄의 값
void go(int st, int en, int d) {
    if(st >= en) return;
    int mid = (st + en) / 2;
    ans[d].push_back(arr[mid]);
    go(st, mid, d+1);
    go(mid + 1, en, d+1);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> level;
    n = pow(2, level) - 1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    go(0, n, 0);
    for(int i = 0; i<level; i++) {
        for(auto x : ans[i])
            cout << x << ' ';
        cout << '\n';
    }
}