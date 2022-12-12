#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int answer = 0;
    for(int i = 0; i< v.size(); i++)
        answer = max(answer, v[i] * (i+1));
    cout << answer << '\n';
    return 0;
}