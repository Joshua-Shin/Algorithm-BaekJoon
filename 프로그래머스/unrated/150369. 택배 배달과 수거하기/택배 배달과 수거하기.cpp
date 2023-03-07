#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    stack <int> d, p;
    for(auto e: deliveries) d.push(e);
    for(auto e: pickups) p.push(e);
    while(!d.empty() && d.top()==0) d.pop();
    while(!p.empty() && p.top()==0) p.pop();
    while(!d.empty() || !p.empty()) {
        answer += max(d.size(), p.size()) * 2;
        int box = 0;
        while(!d.empty() && box <= cap) {
            if(d.top() + box <= cap) {
                box += d.top();
                d.pop();
            }
            else {
                d.top() -= (cap - box);
                break;
            }
        }
        box = 0;
        while(!p.empty() && box <= cap) {
            if(p.top() + box <= cap) {
                box += p.top();
                p.pop();
            }
            else {
                p.top() -= (cap - box);
                break;
            }
        }
    }
    return answer;
}