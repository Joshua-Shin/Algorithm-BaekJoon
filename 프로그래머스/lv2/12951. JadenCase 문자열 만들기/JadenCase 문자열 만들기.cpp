#include <bits/stdc++.h>
using namespace std;
string solution(string s) {
    string answer = "";
    for(int i = 0; i<s.size(); i++)
        answer += (i==0 || s[i-1] == ' ') ? toupper(s[i]) : tolower(s[i]);
    return answer;
}