#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(ll i = begin; i <= end; i++) {
        if(i == 1) {
            answer.push_back(0);
            continue;
        }
        bool flag = false;
        bool flag2 = false;
        ll maxMod = 0;
        for(ll mod = 2; mod * mod <= i; mod++) {
            if(i % mod == 0) {
                ll remain = i / mod;
                if(remain <= 10'000'000) {
                    answer.push_back(remain);
                    flag = true;
                    flag2 = false;
                    break;
                } else if (mod <= 10'000'000) {
                    maxMod = max(maxMod, mod);
                    flag = true;
                    flag2 = true;
                }
            }
        }
        if(!flag) answer.push_back(1);
        if(flag2) answer.push_back(maxMod);
    }
    return answer;
}