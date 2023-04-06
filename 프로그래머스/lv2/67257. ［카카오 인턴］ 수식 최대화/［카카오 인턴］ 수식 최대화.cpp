#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal2(ll a, ll b, char c) {
    if(c == '*') return a * b;
    if(c == '+') return a + b;
    if(c == '-') return a - b;
    return 1;
}
ll cal(vector<char> op, vector<ll> v, vector<char> p) {
    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < op.size(); j++) {
            if(p[i] == op[j]) {
                ll temp = cal2(v[j], v[j+1], op[j]);
                v[j] = temp;
                v.erase(v.begin() + j + 1);
                op.erase(op.begin() + j);
                j = -1;
            }
        }
    }
    return abs(v[0]);
}
long long solution(string expression) {
    long long answer = 0;
    vector<ll> v;
    vector<char> op;
    vector<char> p;
    string num;
    for(int i = 0; i < expression.size(); i++) {
        if('0' <= expression[i] && expression[i] <= '9') {
            num += expression[i];
        } else {
            v.push_back(stoll(num));
            num = "";
            op.push_back(expression[i]);
        }
        if(i == expression.size()-1) v.push_back(stoll(num));
    }
    p = op;
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    do {
        ll result = cal(op, v, p);
        answer = max(answer, result);
    } while (next_permutation(p.begin(), p.end()));
    return answer;
}