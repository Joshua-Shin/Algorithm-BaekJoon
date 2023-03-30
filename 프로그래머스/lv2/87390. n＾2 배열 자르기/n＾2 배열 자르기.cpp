#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(ll k = left; k <= right; k++) {
        ll i = k / n;
        ll j = k % n;
        ll start = i + 1;
        if(j <= i) {
            answer.push_back(start);
            continue;
        }
        ll diff = j - i;
        start += diff;
        answer.push_back(start);
    }
    return answer;
}