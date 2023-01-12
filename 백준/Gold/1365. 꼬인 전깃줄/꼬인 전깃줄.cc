#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i]);
        if(it==v.end()) v.push_back(arr[i]);
        else *it = arr[i];
    }
    cout << n - v.size();
}