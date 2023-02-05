#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    multiset<int> s;
    for(auto str: operations) {
        int num = stoi(str.substr(2));
        if(str[0]=='I') s.insert(num);
        else if(!s.empty())
            (num==-1) ? s.erase(s.begin()) : s.erase(--s.end());
    }
    vector<int> ans(2, 0);
    if(!s.empty()) {
        ans[0] = (*(--s.end()));
        ans[1] = (*s.begin());
    }
    return ans;
}