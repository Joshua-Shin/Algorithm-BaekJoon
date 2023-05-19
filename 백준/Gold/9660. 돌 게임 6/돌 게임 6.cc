#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int r = n % 7;
    if(r ==2 || r ==0) cout << "CY" << '\n';
    else cout << "SK" << '\n';
}