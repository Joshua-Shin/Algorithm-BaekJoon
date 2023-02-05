#include <bits/stdc++.h>
using namespace std;
int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());
    int prevNum = tangerine[0];
    int cnt = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i<=tangerine.size(); i++) {
        if(i==tangerine.size()) {
            v.push_back({cnt, prevNum});
            continue;
        }
        if(prevNum == tangerine[i]) {
            cnt++;
        } else {
            v.push_back({cnt, prevNum});
            cnt = 1;
            prevNum = tangerine[i];
        }
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++) {
        k -= v[i].first;
        if(k <= 0) return i + 1;
    }
    return 0;
}