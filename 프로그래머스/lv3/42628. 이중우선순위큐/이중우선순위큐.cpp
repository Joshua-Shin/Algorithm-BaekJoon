#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) {
    set<int> s;
    for(auto str: operations) {
        char op = str[0];
        int num = stoi(str.substr(2));
        if(op=='I')
            s.insert(num);
        else if(!s.empty()){
            if(num==-1) s.erase(s.begin());             
            else s.erase(--s.end());
        }
    }
    vector<int> ans;
    if(s.empty()) {
        ans.push_back(0);
        ans.push_back(0);
    }
    else {
        ans.push_back(*(--s.end()));
        ans.push_back(*s.begin());
    }
    return ans;
}