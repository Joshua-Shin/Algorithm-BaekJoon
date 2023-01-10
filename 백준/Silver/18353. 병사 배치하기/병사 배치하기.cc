#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    reverse(arr.begin(), arr.end());
    vector<int> v;
    for(int i = 0; i<n; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if(it==v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << n - v.size() << '\n';
    return 0;
}