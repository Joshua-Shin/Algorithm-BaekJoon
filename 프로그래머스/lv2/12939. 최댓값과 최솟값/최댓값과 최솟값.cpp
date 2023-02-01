#include <bits/stdc++.h>
using namespace std;
vector<int> div(string str) {
    istringstream ss(str);
    string strBuffer;
    vector<int> ret;
    while(getline(ss, strBuffer, ' ')) {
        ret.push_back(stoi(strBuffer));
    }
    return ret;
}
string solution(string s) {
    string answer = "";
    auto v = div(s);
    sort(v.begin(), v.end());
    answer += to_string(v.front());
    answer += " ";
    answer += to_string(v.back());
    return answer;
}