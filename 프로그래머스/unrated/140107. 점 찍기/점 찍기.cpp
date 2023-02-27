#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i * k <= d; i++) {
        ll x = i * k;
        ll y = sqrt((ll)d*d - (ll)x*x);
        answer += floor(y / k) + 1;
    }
    return answer;
}