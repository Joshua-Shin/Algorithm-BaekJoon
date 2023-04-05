#include <bits/stdc++.h>
using namespace std;
pair<string, string> div(string p) {
    int cnt1 = 0, cnt2 = 0; // '(' ')' 개수
    string u, v;
    for(int i = 0; i < p.size(); i++) {
        if(p[i] == '(') cnt1++;
        else cnt2++;
        if(cnt1 == cnt2) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            return {u, v};
        }
    }
    return {u, v};
}
bool isRight(string u) {
    stack<char>st;
    for(int i = 0; i < u.size(); i++) {
        if(u[i] == '(') {
            st.push(u[i]);
        } else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}
string revStr(string u) {
    string ret;
    for(int i = 1; i < u.size() -1; i++) {
        if(u[i] == ')') ret += '(';
        else ret += ')';
    }
    return ret;
}
string go(string p) {
    if(p == "") return p;
    string u, v;
    tie(u, v) = div(p);
    if(isRight(u)) return u + go(v);
    return "(" + go(v) + ")"  + revStr(u);
}
string solution(string p) {
    return go(p);
}