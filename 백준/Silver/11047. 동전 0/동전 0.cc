#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    reverse(v.begin(), v.end());
    int answer = 0;
    for(int i = 0; i<v.size(); i++) {
        answer += k / v[i];
        k %= v[i];
    }
    cout << answer << '\n';
    return 0;
}