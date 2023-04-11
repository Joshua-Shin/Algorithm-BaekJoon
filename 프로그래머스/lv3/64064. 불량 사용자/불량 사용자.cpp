#include <bits/stdc++.h>
using namespace std;
bool isMatch(string a, string b) {
    int n = a.size();
    int m = b.size();
    if(n!=m) return false;
    for(int i = 0; i < n; i++) {
        if(!(a[i] == '*' || a[i] == b[i])) return false;
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<string>> ans;
    sort(user_id.begin(), user_id.end());
    do {
        int j = 0;
        vector<string> v;
        for(int i = 0; i < banned_id.size(); i++) {
            for( ; j < user_id.size(); j++) {
                if(isMatch(banned_id[i], user_id[j])) {
                    v.push_back(user_id[j]);
                    j++;
                    break;
                }
            }
        }
        if(v.size() != banned_id.size()) continue;
        sort(v.begin(), v.end());
        ans.push_back(v);
    } while (next_permutation(user_id.begin(), user_id.end()));

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans.size();
}