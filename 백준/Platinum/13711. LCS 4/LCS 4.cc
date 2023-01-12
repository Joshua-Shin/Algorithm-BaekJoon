#include <bits/stdc++.h>
using namespace std;
int n, temp;
int a[100001];
map<int, int> m;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] = i;
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), m[a[i]]);
        if(it==v.end()) v.push_back(m[a[i]]);
        else *it = m[a[i]];
    }
    cout << v.size();
}