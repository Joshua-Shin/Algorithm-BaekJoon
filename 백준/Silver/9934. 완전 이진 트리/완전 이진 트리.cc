#include <bits/stdc++.h>
using namespace std;
int n, level;
int arr[2000];
vector<pair<int, int>> ans; // 층, 값 // stable_sort
void go(int st, int en, int d) {
    if(st==en) return;
    if(st==en-1) {
        ans.push_back({d, arr[st]});
        return;
    }
    int mid = (st + en) / 2;
    ans.push_back({d, arr[mid]});
    go(st, mid, d+1);
    go(mid + 1, en, d+1);
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> level;
    n = pow(2, level) - 1;
    for (int i = 0; i < n; i++) cin >> arr[i];
    go(0, n, 0);
    stable_sort(ans.begin(), ans.end(), cmp);
    // for(auto x: ans) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    // cout << "=======" << '\n';
    int cntLevel = 0;
    for(int i = 0; i<ans.size(); i++) {
        if(ans[i].first==cntLevel) {
            cout << ans[i].second << ' ';
        }
        else {
            cntLevel++;
            cout << '\n';
            i--;
        }
    }
}