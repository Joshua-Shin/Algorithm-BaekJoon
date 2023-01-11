#include <bits/stdc++.h>
using namespace std;
int n, temp;
int arr[10000];
int brr[10000];
map<int, int> m; // 전구번호, 위치
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] = i;
        brr[i] = temp;
    }
    vector<int> v, ans;
    vector<pair<int, int>> rec;
    for(int i = 0; i<n; i++) {
        auto it = lower_bound(v.begin(), v.end(), m[arr[i]]);
        int idx = it - v.begin();
        // cout << "idx: " << idx << '\n';
        if(it==v.end()) v.push_back(m[arr[i]]);
        else *it = m[arr[i]];
        rec.push_back({idx, m[arr[i]]});
    }
    // for(auto x : v) cout << x << ' ';
    int len = v.size() -1;
    cout << len + 1 << '\n';
    // for(auto x: rec) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }
    for(int i = rec.size()-1; i>=0; i--) {
        if(rec[i].first == len) {
            len--;
            ans.push_back(brr[rec[i].second]);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x: ans) cout << x << ' ';
    return 0;
}