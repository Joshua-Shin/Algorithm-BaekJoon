#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tc, n, temp;
// 1,000,000 * 10,000 = 10^6 * 10^4 = 10^10
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> tc;
    vector<ll> answer;
    while(tc--) {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            pq.push(temp);
        }
        ll ans = 0;
        while(pq.size()!=1) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ll sum = a + b;
            pq.push(sum);
            ans += sum;
        }
        answer.push_back(ans);
    }
    for(auto x: answer) cout << x << '\n';
}