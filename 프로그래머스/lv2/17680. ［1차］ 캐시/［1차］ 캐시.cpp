#include <bits/stdc++.h>
using namespace std;
int isContain(vector<string> &v, string s) {
    for(int i = 0; i<v.size(); i++) {
        if(v[i]==s) return i;
    }
    return -1;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0)
        return cities.size() * 5;
    for(auto &c: cities) {
        for(int i = 0; i < c.size(); i++) {
            c[i] = tolower(c[i]);
        }
    }
    vector<string> v;
    for(auto c: cities) {
        if(v.empty()) {
            v.push_back(c);
            answer+=5;
            continue;
        }
        int idx = isContain(v, c);
        if(idx != -1) { // 찾았다면, 뒤로 빼고.
            v.erase(v.begin() + idx);
            answer++;
        } else { // 못찾았다면,
            if(v.size() == cacheSize) v.erase(v.begin());
            answer += 5;
        }
        v.push_back(c);
    }
    return answer;
}