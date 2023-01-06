#include <bits/stdc++.h>
using namespace std;
int a[501];
int d[501];
int n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    // for(int i = 1; i< 501; i++)
    //     a[i] = 2e9;
    for (int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        a[t1] = t2;
    }
    for(int i = 1; i<501; i++) {
        if(a[i]==0) continue;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                d[i] = max(d[i], d[j] +1);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<501; i++)
        ans = max(ans, d[i]);
    cout << n - ans << '\n';
    return 0;
}