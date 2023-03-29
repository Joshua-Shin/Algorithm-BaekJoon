#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, vector<string> words) {
    map<string, int> m;
    for(int i = 0; i<words.size(); i++) {
        if(m[words[i]] || (i != 0 && words[i-1][words[i-1].size()-1] != words[i][0])) return {i % n + 1, i / n + 1};
        m[words[i]]++;
    }
    return {0, 0};
}