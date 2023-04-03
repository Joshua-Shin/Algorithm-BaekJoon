#include <bits/stdc++.h>
using namespace std;
vector<string> div(string str) {
    vector<string> ret;
    istringstream ss(str);
    string buf;
    while(getline(ss, buf, ' ')) {
        ret.push_back(buf);
    }
    return ret;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    // 유저아이디에 따른 최종닉네임을 저장해둬야함
    map<string, string> m;
    for(auto r: record) {
        if(r[0] == 'L') continue;
        vector<string> v = div(r);
        m[v[1]] = v[2];
    }
    for(auto r: record) {
        vector<string> v = div(r);
        string str = m[v[1]];
        if(v[0] == "Enter") str += "님이 들어왔습니다.";
        else if(v[0] == "Leave") str += "님이 나갔습니다.";
        else continue;
        answer.push_back(str);
    }
    return answer;
}