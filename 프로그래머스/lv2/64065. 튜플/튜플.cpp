#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}
vector<string> div(string str) {
    vector<string> ret;
    istringstream ss(str);
    string buf;
    while(getline(ss, buf, ' ' )) {
        ret.push_back(buf);
    }
    return ret;
}
vector<int> div2(string str) {
    vector<int> ret;
    istringstream ss(str);
    string buf;
    while(getline(ss, buf, ',' )) {
        ret.push_back(stoi(buf));
    }
    return ret;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> v;
    s = s.substr(1, s.size()-2);
    // cout << s << '\n';
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i-1]=='}'&& s[i]==',' && s[i+1]=='{') s[i]=' ';
    }
    // cout << s << '\n';
    vector<string> divStr = div(s);
    for(auto d: divStr) {
        // cout << d << '\n';
        d = d.substr(1, d.size()-2);
        v.push_back(div2(d));
    }
    // cout << v.size() << '\n';
    // for(auto x: v) {
        // for(auto y: x) cout << y << ' ';
        // cout << '\n';
    // }
    sort(v.begin(), v.end(), cmp);
    map<int, int> m;
    for(int i = 0; i< v.size(); i++) {
        for(int j = 0; j<v[i].size(); j++) {
            if(m[v[i][j]]) continue;
            m[v[i][j]]++;
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}