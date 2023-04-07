#include <bits/stdc++.h>
using namespace std;
map<string, int> key;
bool isRight(string keyName) {
    sort(keyName.begin(), keyName.end());
    do
    {
        for(auto iter = key.begin(); iter != key.end(); iter++) {
            if(keyName.find((*iter).first) != -1) return false;
        }
    } while (next_permutation(keyName.begin(), keyName.end()));
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    // 속성 하나씩 선택해서, 후보키되나 확인.
    // 후보키가 아닌 속성중에 n개의 속성 선택하여 후보키 되나 확인
    int n = relation.size();
    int m = relation[0].size();
    
    for(int sel = 1; sel <= m; sel++) { // 선택할 속성의 수
        vector<int> v(m, 1);
        for(int i = 0; i < m - sel; i++) v[i] = 0;

        do {
            string str[21];
            set<string> s;
            vector<int> v2; // 후보키후보
            for(int j = 0; j < m; j++) {
                if(v[j] == 0) continue; // 선택하지 않은 컬럼은 스킵
                v2.push_back(j);
                for(int i = 0; i < n; i++) {
                    str[i] += relation[i][j];
                }
            }
            for(int i = 0; i < n; i++) {
                s.insert(str[i]);
            }
            if(s.size() == n) { // 이것도 말이 안되는게, {이름, 학년}이 후보키일때 {이름, 전공, 학년}이면 안되는걸 못잡아냄.
                string keyName;
                for(auto x: v2) {
                    keyName += to_string(x);
                }
                if(isRight(keyName)) {
                    answer++;
                    key[keyName] = 1;
                }
            }
        } while (next_permutation(v.begin(), v.end()));

    }
    return answer;
}