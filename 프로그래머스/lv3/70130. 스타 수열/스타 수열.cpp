#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a) {
    // int maxValue = *max_element(a.begin(), a.end());
    vector<int> v = a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // for(auto x: v) cout << x << ' ';
    // cout << '\n';
    map<int,int> m;
    for(auto x: a) m[x]++;
    bool check[a.size()];
    int maxCnt = 0;
    for(int j = 0; j < v.size(); j++) {
        if(m[v[j]] <= maxCnt) continue;
        memset(check, false, sizeof(check));
        // cout << "===========" << '\n';
        // for(auto x: check) cout << x << ' ';
        // cout << '\n';
        // cout << "===========" << '\n';
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != v[j] || check[i]) continue;
            if(i!=0 && check[i-1]==false && a[i-1]!=a[i]) {
                check[i-1] = true;
                check[i] = true;
                cnt++;
            } else if (i!=a.size()-1 && a[i] != a[i+1]) {
                check[i] = true;
                check[i+1] = true;
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
        // cout << v[j] << ' ' << maxCnt << '\n';
    }
    return maxCnt * 2;
}