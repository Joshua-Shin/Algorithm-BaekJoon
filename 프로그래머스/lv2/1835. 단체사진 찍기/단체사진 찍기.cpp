#include <bits/stdc++.h>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool isOk(string &d, vector<char> &v) {
    char f1 = d[0];
    char f2 = d[2];
    int idx1, idx2;
    for(int i = 0; i<v.size(); i++) {
        if(v[i]==f1) idx1 = i;
        if(v[i]==f2) idx2 = i;
    }
    int dif = abs(idx1 - idx2) - 1;
    int num = d[4] - '0';
    if(d[3] == '=') {
        if(num == dif) return true;
    } else if(d[3] == '<') {
        if(num > dif) return true;
    } else { // '>'
        if(num < dif) return true;
    }
    return false;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do {
        bool flag = false;
        for(auto d: data) {
            if(!isOk(d, v)) {
                flag = true;
                break;
            }
        }
        if(!flag) answer++;
    } while (next_permutation(v.begin(), v.end()));
    return answer;
}