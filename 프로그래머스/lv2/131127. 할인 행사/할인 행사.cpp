#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int answer;
vector<string> want;
vector<int> number;
bool check() {
    for(int i = 0; i<want.size(); i++) {
        if(m[want[i]]>=number[i]) continue;
        return false;
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    ::want = want;
    ::number = number;
    for(int i = 0; i < 10; i++)
        m[discount[i]]++;
    if(check()) answer++;
    for(int i = 1; i < discount.size()-9; i++) {
        m[discount[i-1]]--;
        m[discount[i+9]]++;
        if(check()) answer++;
    }
    return answer;
}