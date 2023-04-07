#include <bits/stdc++.h>
using namespace std;
int press(string s, int len) {
    vector<string> v;
    for(int i = 0; i < s.size(); i+=len) {
        v.push_back(s.substr(i, len));
    }
    string str;
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size()-1 && v[i] == v[i+1]) {
            int cur = i + 1;
            int cnt = 2;
            while(1) {
                cur++;
                cnt++;
                if(cur == v.size() || v[i] != v[cur]) {
                    cnt--;
                    break;
                }
            }
            str += (to_string(cnt) + v[i]);
            if(cur == v.size()) break;
            else i = cur - 1;
        } else {
            str += v[i];
        } 
    }
    return str.size();
}
int solution(string s) {
    if(s.size()==1) return 1;
    int answer = 1e9;
    int n = s.size() / 2;
    for(int i = 1; i <= n; i++) {
        answer = min(answer, press(s, i));
    }
    return answer;
}