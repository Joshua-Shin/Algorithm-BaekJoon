#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    vector<pair<int, int>> ans;
    cin >> n;
    vector <int> v;
    for(int i =0; i<n; i++) {
        int temp;
        cin >> temp;
        auto iter = lower_bound(v.begin(), v.end(), temp);
        int idx = iter - v.begin();
        // cout << idx << '\n';
        if(iter==v.end())
            v.push_back(temp);
        else
            (*iter) = temp; 
        ans.push_back({idx, temp});
    }
    cout << v.size() << '\n';
    // for(auto x: v) cout << x << ' ';
    int len = v.size() - 1;
    stack<int> s;
    for(int i = n -1; i>=0; i--) {
        if(ans[i].first==len) {
            len--;
            s.push(ans[i].second);
        }
    }
    while(!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}