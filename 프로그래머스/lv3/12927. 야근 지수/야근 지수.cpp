#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(auto x: works) pq.push(x);
    while(n--) {
        int x = pq.top();
        if(!x) break;
        pq.pop();
        pq.push(--x);
    }
    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        answer += (ll)x * x;
    }
    return answer;
}