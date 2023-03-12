#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
string convert(ll num) {
    string ret;
    while(num) {
        ret += to_string(num % 2);
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
bool dfs(int st, int en, bool isDummy) {
    if(st > en) return true;
    int mid = (st + en) / 2;
    if(str[mid] == '1' && isDummy) return false;
    return dfs(st, mid-1, str[mid]=='0') && dfs(mid+1, en, str[mid]=='0');
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto num: numbers) {
        str = convert(num);
        int diff;
        for(int i = 0; ; i++) {
            if(pow(2, i) -1 < str.size()) continue;
            diff = pow(2, i) -1 - str.size();
            break;
        }
        while(diff--) str = '0' + str;
        dfs(0, str.size()-1, false) ? answer.push_back(1): answer.push_back(0);
    }
    return answer;
}