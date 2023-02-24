#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MX = 100'001;
int arr[MX];
int main() {
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int st = 0, en = 0;
    int answer = 2e9;
    while(st < n && en < n) {
        int result = abs(arr[st] - arr[en]);
        if(result > m) {
            answer = min(answer, result);
            st++;
        }
        if(result == m) {
            cout << result << '\n';
            return 0;
        }
        if(result < m) {
            en++;
        }
    }
    cout << answer << '\n';
}