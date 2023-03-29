#include <bits/stdc++.h>
using namespace std;
map<char, char> m;
bool isRight(string s) {
    stack <char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty() || m[st.top()] != s[i]) return false;
            st.pop();
        }
    }
    return st.empty();
}
string convert(string s) {
    string ret = s.substr(1);
    ret += s[0];
    return ret;
}
int solution(string s) {
    m['('] = ')';
    m['{'] = '}';
    m['['] = ']';
    int answer = 0;
    int n = s.size();
    while(n--) {
        if(isRight(s)) answer++;
        s = convert(s);
    }
    return answer;
}