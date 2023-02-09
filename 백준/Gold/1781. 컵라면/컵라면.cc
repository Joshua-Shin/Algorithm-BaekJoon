#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    for(int i = 1; i<=n && cur < v.size(); cur++) {
        if(pq.empty() || v[cur].first >= i) {
            pq.push(v[cur].second);
            i++;
        } else if(v[cur].second > pq.top()) {
            pq.pop();
            pq.push(v[cur].second);
        } 
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
}