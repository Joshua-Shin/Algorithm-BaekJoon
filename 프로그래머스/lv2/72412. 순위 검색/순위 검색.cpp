#include <bits/stdc++.h>
using namespace std;
vector<string> findKey;
vector<vector<string>> option;
vector<string> div(string s) {
    vector<string> ret;
    istringstream ss(s);
    string buf;
    while(getline(ss, buf, ' ')) {
        if(buf == "and") continue;
        ret.push_back(buf);
    }
    return ret;
}
void makeKey(vector<string> v, int cur) {
    if(cur == 4) {
        string key = v[0] + v[1] + v[2] + v[3];
        findKey.push_back(key);
        return;
    }
    if(v[cur] == "-") {
        for(auto e: option[cur]) {
            v[cur] = e;
            makeKey(v, cur+1);
        }
    } else {
        makeKey(v, cur+1);
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<string> temp1 = {"cpp", "java", "python"};
    vector<string> temp2 = {"backend", "frontend"};
    vector<string> temp3 = {"junior", "senior"};
    vector<string> temp4 = {"chicken", "pizza"};
    option.push_back(temp1); option.push_back(temp2); 
    option.push_back(temp3); option.push_back(temp4);
    map <string, vector<int>> m; //
    for(auto e: info) {
        auto v = div(e);
        string key = v[0] + v[1] + v[2] + v[3];
        int value = stoi(v[4]);
        m[key].push_back(value);
        // auto v2 = m[key];
        // v2.push_back(value);
        // m[key] = v2;
    }
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        sort((*iter).second.begin(), (*iter).second.end());
    }
    // for(auto iter = m.begin(); iter != m.end(); iter++) {
    //     auto v = (*iter).second;
    //     for(auto x: v) cout << x << ' ';
    //     cout << '\n';
    // }
    for(auto e: query) { // 100,000
        auto v = div(e);
        findKey.clear();
        makeKey(v, 0);
        int limitValue = stoi(v[4]);
        int cnt = 0;
        for(auto k: findKey) { // 24개
            m[k]; // vector<int>
            auto iter = lower_bound(m[k].begin(), m[k].end(), limitValue);
            cnt += (m[k].end() - iter);
            // for(auto x: m[k]) { /// 아무리 분류해도 결국 최대 100,000개 아님??// 이분탐색하면 어때??
            //     if(limitValue <= x) cnt++;
            //     else break;
            // }
        }
        answer.push_back(cnt);
    }
    return answer;
}