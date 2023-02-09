#include <bits/stdc++.h>
using namespace std;
int n, temp; // 100,000
int main() {
    cin.tie(0)->sync_with_stdio(0);
    priority_queue <int> maxPq;
    priority_queue <int, vector<int>, greater<int>> minPq;
    cin >> n;
    while(n--) {
        cin >> temp;
        if(maxPq.empty())
            maxPq.push(temp);
        else if(maxPq.size()==minPq.size())
            maxPq.push(temp);
        else
            minPq.push(temp);
        if(!maxPq.empty() && !minPq.empty()) {
            int a = maxPq.top();
            int b = minPq.top();
            if(a > b) {
                maxPq.pop();
                minPq.pop();
                maxPq.push(b);
                minPq.push(a);
            }
        }
        cout << maxPq.top() << '\n';
    }
}