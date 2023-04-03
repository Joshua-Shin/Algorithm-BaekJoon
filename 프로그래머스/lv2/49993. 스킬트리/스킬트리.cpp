#include <bits/stdc++.h>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto s: skill_trees) {
        int skillCur = 0;
        for(int i = 0; i<s.size(); i++) {
            int x = skill.find(s[i]);
            if(x == -1) continue;
            if(x == skillCur) {
                skillCur++;
                continue;
            } else {
                goto out;
            }
        }
        answer++;
        out:;
    }
    return answer;
}