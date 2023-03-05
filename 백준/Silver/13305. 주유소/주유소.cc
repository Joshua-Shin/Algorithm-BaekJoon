#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dist;
vector<int> cost;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dist.resize(n - 1);
    cost.resize(n);
    int totalDist = 0;
    for(int i = 0; i < n -1; i++) {
        cin >> dist[i];
        totalDist += dist[i];
    }
    int minCostIdx = 0;
    int minCost  = 1e9;
    for(int i = 0; i< n ; i++) {
        cin >> cost[i];
        if(i == n-1) continue;
        if(minCost > cost[i]) {
            minCost = cost[i];
            minCostIdx = i;
        }
    }
    int sum = 0;
    for(int i = 0; i< n; i++) {
        if(i == minCostIdx) {
            sum += cost[i] * totalDist;
            cout << sum << '\n';
            return 0;
        } else {
            sum += dist[i] * cost[i];
            totalDist -= dist[i];
        }
    }
}