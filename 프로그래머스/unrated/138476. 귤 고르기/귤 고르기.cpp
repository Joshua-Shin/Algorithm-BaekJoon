#include <bits/stdc++.h>
using namespace std;
int solution(int k, vector<int> tangerine) {
    vector<int> v(*max_element(tangerine.begin(), tangerine.end())+ 1, 0);
    for(auto x: tangerine) v[x]++;
    sort(v.rbegin(), v.rend());
    for(int i = 0; i<v.size(); i++) {
        k -= v[i];
        if(k <=0) return i + 1;
    }
}