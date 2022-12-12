#include <bits/stdc++.h>
using namespace std;
int a[51], b[51];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);
    int answer = 0;
    for (int i = 0; i < n; i++)
        answer += a[i] * b[i];
    cout << answer << '\n';
    return 0;
}