#include <bits/stdc++.h>
using namespace std;
int n;
int dp(int n) {
    if(n==1 || n == 3) return 0;
    if(n==2) return 1;
    return !dp(n-3);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    (dp(n)) ? cout << "CY" : cout << "SK";
}