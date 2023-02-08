#include <bits/stdc++.h>
using namespace std;
int n, temp;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    priority_queue<pair<int, int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq3;
    while(n--) {
        cin >> temp;
        if(temp < 0) pq3.push({-temp, temp});
        else if(temp > 0) pq3.push({temp, temp});
        else {
            if(pq3.empty()) pq3.push({0, 0});
            cout << pq3.top().second << '\n';
            pq3.pop();
        }
    }
}