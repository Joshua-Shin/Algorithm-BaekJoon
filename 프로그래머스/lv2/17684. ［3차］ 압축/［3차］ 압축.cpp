#include <bits/stdc++.h>
using namespace std;
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int seq = 1;
    for(char i = 'A'; i <= 'Z'; i++){
        string s(1, i);
        m[s] = seq++;
    }
    // cout << m["A"] << ' ' << m["Z"] << '\n';
    for(int i = 0; i < msg.size(); i++) {
        int end = i;
        string temp;
        while(1) {
            temp += msg[end];
            if(m.find(temp) == m.end()) break;
            end++;
        }
        m[temp] = seq++;
        temp.pop_back();
        answer.push_back(m[temp]);
        i += temp.size()-1;
    }
    return answer;
}