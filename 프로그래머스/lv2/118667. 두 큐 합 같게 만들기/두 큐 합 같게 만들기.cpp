#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int solution(vector<int> v1, vector<int> v2) {
    int answer = 0;
    ll sum1 = accumulate(v1.begin(), v1.end(), 0LL);
    ll sum2 = accumulate(v2.begin(), v2.end(), 0LL);
    ll sum = sum1 + sum2;
    if(sum % 2 != 0) return -1;
    sum /= 2;

    queue<int> q1, q2;
    for(auto x: v1) {
        q1.push(x);
    }
    for(auto x: v2) {
        q2.push(x);
    }

    while(sum1 != sum) {
        if(sum1 > sum2) {
            ll temp = q1.front();
            q2.push(temp);
            sum1 -= temp;
            sum2 += temp;
            q1.pop();
        } else {
            ll temp = q2.front();
            q1.push(temp);
            sum2 -= temp;
            sum1 += temp;
            q2.pop();
        }
        answer++;
        if(answer > 600000) return -1;
    }
    return answer;
}