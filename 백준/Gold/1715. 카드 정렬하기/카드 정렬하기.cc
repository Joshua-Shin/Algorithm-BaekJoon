#include <bits/stdc++.h>
using namespace std;
int n, temp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }
    if(n==1) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 0;
    while(pq.size()!=1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        pq.push(sum);
        ans += sum;        
    }
    cout << ans;
}