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
    int currentTime = 1;
    for(int i = 0; i<v.size(); i++) {
        if(currentTime <= v[i].first) {
            pq.push(v[i].second);
            currentTime++;
        }
        else if(pq.top() < v[i].second) {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}