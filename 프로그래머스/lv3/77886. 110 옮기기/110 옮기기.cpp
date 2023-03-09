#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto str: s) {
        int cnt = 0;
        int n = str.size();
        for(int i = 0; i< n-2; i++) {
            if(str[i]=='1' && str[i+1] == '1' && str[i+2] == '0') {
                cnt++;
                str.erase(str.begin() + i, str.begin()+i+3);
                i-= 3;
                n = str.size();
            }
        }
        int lastZeroIdx = -1;
        for(int i = str.size()-1; i>=0; i--) {
            if(str[i] == '0') {
                lastZeroIdx = i;
                break;
            }
        }
        string result;
        if(lastZeroIdx == -1) {
            while(cnt--) result += "110";
            result += str;
        } else {
            result += str.substr(0, lastZeroIdx + 1);
            while(cnt--) result += "110";
            result += str.substr(lastZeroIdx+1);
        }
        answer.push_back(result);
    }
    return answer;
}