#include <bits/stdc++.h>
using namespace std;
int n, l;
bool isValid(int k) {
    while(k) {
        if(k % 10 == l) return false;
        k /= 10;
    }
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    int k = 1;
    for(int i = 1; i <= n; i++) {
        while(1) {
            if(isValid(k)) break;
            else k++;
        }
        k++;
    }
    cout << k - 1 << '\n';
    return 0;
}