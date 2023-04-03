#include <bits/stdc++.h>
using namespace std;
string convert(string s) {
    for(auto &c: s) {
        c = tolower(c);
    }
    return s;
}
bool cmp(vector<string> a, vector<string> b) {
    string headA = convert(a[1]);
    string headB = convert(b[1]);
    if(headA != headB) return headA < headB;
    int numberA = stoi(a[2]);
    int numberB = stoi(b[2]);
    if(numberA != numberB) return numberA < numberB;
    return stoi(a[3]) < stoi(b[3]);
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    // 파일명, head, number로 갱신하고, stable_sort한다음에, 파일명만 answer로 넘기면 됨.
    // stable_sort가 웬지 신뢰가 안되어서, 입력 받은 순서로 v에 넣어서 정렬 시킴.
    vector<vector<string>> v; 
    int idx = 0;
    for(auto f: files) {
        int st = 0, en = 0;
        for(int i = 0; i < f.size(); i++) {
            if('0' <= f[i] && f[i] <= '9') {
                st = i;
                for(int j = i + 1; j < f.size(); j++) {
                    if(!('0' <= f[j] && f[j] <= '9')) {
                        en = j;
                        goto out;
                    }
                    if(j == f.size()-1 && ('0' <= f[j] && f[j] <= '9')) {
                        en = j + 1;
                        goto out;
                    }
                }
            }
        }
        out:;
        string head = f.substr(0, st);
        string number = f.substr(st, en - st);
        v.push_back({f, head, number, to_string(idx++)});
    }
    // for(auto x: v) {
    //     cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    // }
    sort(v.begin(), v.end(), cmp);
    for(auto x: v) {
        answer.push_back(x[0]);
    }
    return answer;
}