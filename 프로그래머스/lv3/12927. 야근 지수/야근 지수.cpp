#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    for(auto x: works) q.push(x);
    while(n--) {
        int x = q.top();
        q.pop();
        if(x == 0) return 0;
        q.push(--x);
    }
    while(!q.empty()) {
        ll temp = q.top();
        q.pop();
        answer += (ll)temp * temp;
    }
    return answer;
}