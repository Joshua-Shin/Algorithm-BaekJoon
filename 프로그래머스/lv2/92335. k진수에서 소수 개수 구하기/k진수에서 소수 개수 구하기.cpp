#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string convert(int n, int k) {
    string ret;
    while(n) {
        ret += to_string(n % k);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
vector<ll> div(string s) {
    vector<ll> ret;
    string buf;
    istringstream ss(s);
    while(getline(ss, buf, '0')) {
        if(buf=="") continue;
        ret.push_back(stoll(buf));
    }
    // stack<char> st;
    // for(int i = 0; i<s.size(); i++) {
    //     if(s[i] == '0') {
    //         string temp;
    //         while(!st.empty()) {
    //             temp += st.top();
    //             st.pop();
    //         }
    //         if(temp.size()==0) continue;
    //         reverse(temp.begin(), temp.end());
    //         ret.push_back(stoi(temp));
    //     } else {
    //         st.push(s[i]);
    //         if(i == s.size()-1) {
    //             string temp;
    //             while(!st.empty()) {
    //                 temp += st.top();
    //                 st.pop();
    //             }
    //             if(temp.size()==0) continue;
    //             reverse(temp.begin(), temp.end());
    //             ret.push_back(stoi(temp));
    //         }
    //     }
    // }
    return ret;
}
bool isPrime(ll x) {
    if(x == 1) return false;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false; 
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s = convert(n, k);
    cout << s << '\n';
    vector<ll> v = div(s);
    for(auto x: v) {
        // cout << x << '\n';
        if(isPrime(x)) answer++;
    }
    return answer;
}