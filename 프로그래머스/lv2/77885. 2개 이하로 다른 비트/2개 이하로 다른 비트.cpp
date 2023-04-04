#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cal(ll number) {
    int ret = 1;
    while(number) {
        if(number % 2 == 1) ret ++;
        else break;
        number /= 2;
    }
    return ret;
}
ll convertToll(string s) {
    int idx = -1;
    ll ret = 0;
    for(int i = s.size()-1; i >= 0; i--) {
        idx++;
        if(s[i]=='0') continue;
        ret += (ll)pow(2, idx);
    }
    return ret;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto number: numbers) {
        int n = cal(number);
        if(n==1 || n ==2){
            answer.push_back((ll)number + 1);
            continue;
        }
        // n == 3 / str = "011" 이 값을 101. 
        string s(n-1, '1');
        s = "0" + s;
        string s2(n-2, '1');
        s2 = "10" + s2;
        // cout << s << '\n';
        // cout << s2 << '\n';
        ll a = convertToll(s);
        ll b = convertToll(s2);
        // cout << stoll(s2) << '\n';
        // cout << stoll(s) << '\n';
        answer.push_back((ll)number + b - a);
        // answer.push_back((ll)stoll(str2) - stoll(str));
    }
    return answer;
}