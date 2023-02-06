#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
bool isConnect(string s, string ns) {
    int cnt = 0;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] != ns[i]) cnt++;
        if(cnt == 2) return false;
    }
    return cnt;
}
int solution(string begin, string target, vector<string> words) {
    queue<string> q;
    m[begin] = 0;
    q.push(begin);
    while(!q.empty()) {
        string s = q.front();
        q.pop();
        for(auto ns: words) {
            if(m[ns]) continue;
            if(!isConnect(s, ns)) continue;
            m[ns] = m[s] + 1;
            q.push(ns);
        }
    }
    return m[target];
}