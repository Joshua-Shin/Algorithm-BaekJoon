#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    vector<pair<int, int>> recode;
    for(int i = 0; i<n; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        int idx = it - v.begin();
        if(it==v.end()) v.push_back(arr[i]);
        else *it = arr[i];
        recode.push_back({idx, arr[i]});
    }
    int len = v.size();
    cout << len << '\n';
    len--;
    vector<int> ans;
    for(int i = recode.size()-1; i >= 0; i--) {
        if(recode[i].first == len) {
            ans.push_back(recode[i].second);
            len--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x: ans) cout << x << ' ';
    return 0;
}