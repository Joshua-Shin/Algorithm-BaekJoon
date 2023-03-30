#include <bits/stdc++.h>
using namespace std;
vector<string> convert(string str) {
    vector<string> ret;
    for(int i = 0; i<str.size(); i++) str[i] = tolower(str[i]);
    for(int i = 0; i < str.size()-1; i++) {
        if(!('a' <= str[i] && str[i] <= 'z' && 'a' <= str[i+1] && str[i+1] <= 'z')) continue;
        ret.push_back(str.substr(i, 2));
    }
    return ret;
}
int cal(vector<string> &v1, vector<string> &v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int p1 = 0, p2 = 0;
    int cnt = 0;
    while(p1 < v1.size() && p2 < v2.size()) {
        if(v1[p1] == v2[p2]) {
            p1++; p2++; cnt++;
        } else if(v1[p1] < v2[p2]){
            p1++;
        } else {
            p2++;
        }
    }
    return cnt;
}
int solution(string str1, string str2) {
    int answer = 0;
    // 다중집합의 원소로 만들기
    vector<string> v1 = convert(str1);
    vector<string> v2 = convert(str2);
    if(v1.size()==0 && v2.size()== 0) return 65536;
    // 교집합의 크기 구하기. 구하면 union all 사이즈에서 빼면 합집합 크기 구해짐
    int intersectSize = cal(v1, v2);
    int unionSize = v1.size() + v2.size() - intersectSize;
    // 65536 곱하고 int로 반환
    return intersectSize * 65536 / unionSize;
}