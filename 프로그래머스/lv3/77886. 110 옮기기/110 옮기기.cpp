#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto str: s) {
        int n = str.size();
        int cnt = 0;
        for(int i = 0; i < n - 2; i++) {
            if(!(str[i] == '1' && str[i+1] == '1' && str[i+2] == '0')) continue;
            str.erase(str.begin()+i, str.begin()+i+3);
            n = str.size();
            i -= 3;
            cnt++;
        }
        int zeroIdx = -1;
        for(int i = n -1; i >=0; i--) {
            if(str[i] != '0') continue;
            zeroIdx = i;
            break;
        }
        string result;
        if(zeroIdx == -1) {
            while(cnt--) result += "110";
            result += str;
            answer.push_back(result);
            continue;
        }
        result = str.substr(0, zeroIdx + 1);
        while(cnt--) result += "110";
        result += str.substr(zeroIdx + 1);
        answer.push_back(result);
    }
    return answer;
}