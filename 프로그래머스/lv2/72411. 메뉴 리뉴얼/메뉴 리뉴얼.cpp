#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto &o: orders) sort(o.begin(), o.end());
    // int n = *max_element(course.begin(), course.end());

    map<string, int> menu;
    // int cnt[11] = {0}; // 이거 다 0으로 초기화 되는거 맞지? // cnt[2] : 2개조합일때의 최대 주문히
    for(auto s: orders) {
        int n = s.size();
        for(int i = 0; i < course.size(); i++) {
            int m = course[i];
            if(m > n) continue;
            vector<int> v(n, 0);
            for(int j = n - m; j < n; j++) {
                v[j] = 1;
            }
            do {
                string str;
                for(int j = 0; j < v.size(); j++) {
                    if(v[j]==0) continue;
                    str += s[j];
                }
                menu[str]++;
            } while (next_permutation(v.begin(), v.end()));
        }
    }
    vector<string> v[11];
    for(auto iter = menu.begin(); iter != menu.end(); iter++) {
        string a = (*iter).first;
        int cnt = (*iter).second;
        if(cnt <= 1) continue;
        int n = a.size();
        if(v[n].empty()) {
            v[n].push_back(a);
        }
        else if(menu[v[n][0]] < cnt) {
            v[n].clear();
            v[n].push_back(a);
        }
        else if(menu[v[n][0]] == cnt) {
            v[n].push_back(a);
        }
    }
    for(int i = 0; i < course.size(); i++) {
        for(auto x: v[course[i]]) {
            answer.push_back(x);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}