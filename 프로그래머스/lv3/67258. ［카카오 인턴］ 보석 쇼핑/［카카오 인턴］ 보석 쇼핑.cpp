#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    for(auto g: gems) s.insert(g);
    int n = s.size();
    int st = 0, en = 0;
    set<string> s2;
    s2.insert(gems[st]);
    int len = 2e9;
    int ansSt, ansEn;
    map<string, int> m;
    m[gems[st]]++;
    while(st <= en && st < gems.size() && en < gems.size()) {
        if(s2.size() < n) {
            en++;
            if(en == gems.size()) break;
            s2.insert(gems[en]);
            m[gems[en]]++;
        } else if (s2.size() >= n) {
            int diff = en - st + 1;
            if(len > diff) {
                len = diff;
                ansSt = st;
                ansEn = en;
            }
            m[gems[st]]--;
            if(m[gems[st]]==0)
                s2.erase(gems[st]);
            st++;
        } 
    }
    return {ansSt+1, ansEn+1};
}