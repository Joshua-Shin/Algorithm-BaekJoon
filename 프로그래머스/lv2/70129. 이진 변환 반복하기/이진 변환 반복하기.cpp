#include <bits/stdc++.h>
using namespace std;
int delCnt;
int opCnt;
string convert(string s) {
    string ret;
    for(auto c: s) {
        if(c =='1') ret += '1';
    }
    delCnt += s.size() - ret.size();
    return ret;
}
string convert2(int x) {
    string ret;
    while(x) {
        ret += to_string(x % 2);
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
vector<int> solution(string s) {
    while(s != "1") {
        s = convert(s);
        s = convert2(s.size());
        opCnt++;
    }
    return {opCnt, delCnt};
}