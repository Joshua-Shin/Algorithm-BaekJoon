#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr;
int cache[10001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cache[0] = 1;
    for (int i = 0; i < n; i++)
        for(int j = arr[i]; j <= k; j++)
            cache[j] += cache[j - arr[i]];
    cout << cache[k] << '\n';
}