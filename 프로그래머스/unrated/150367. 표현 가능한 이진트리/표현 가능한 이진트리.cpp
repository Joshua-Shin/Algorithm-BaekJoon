#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool dfs(int st, int en, bool prevNodeIsDummy, string str) {
    if(st > en) return true;
    int mid = (st + en) / 2;
    if(str[mid]=='1' && prevNodeIsDummy) return false;
    return dfs(st, mid-1, str[mid]=='0', str) && dfs(mid+1, en, str[mid]=='0', str);
}
string convertBinary(string str) {
    string ret;
    ll n = stoll(str);
    while(n) {
        ret += to_string(n % 2);
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto num: numbers) {
        string str = to_string(num);
        str = convertBinary(str);
        for(int i = 0; ; i++) {
            int maxLen = pow(2, i) -1;
            if(maxLen < str.size()) continue;
            int diff = maxLen - str.size();
            while(diff--) {
                str = '0' + str;
            }
            break;
        }
        dfs(0, str.size() - 1, false, str) ? answer.push_back(1) : answer.push_back(0);
    }
    return answer;
}