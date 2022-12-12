#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second!= b.second) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), cmp);
    int answer = 0, end = -1;
    for(int i = 0; i<v.size(); i++) {
        if(v[i].first >= end) {
            end = v[i].second;
            answer++;
        }
    }
    cout << answer << '\n';
    return 0;
}