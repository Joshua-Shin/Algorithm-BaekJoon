#include <bits/stdc++.h>
using namespace std;
int n, temp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if(pq.size() < n)
                pq.push(temp);
            else if(pq.top() < temp) {
                pq.pop();
                pq.push(temp);
            }
        }
    cout << pq.top();
}