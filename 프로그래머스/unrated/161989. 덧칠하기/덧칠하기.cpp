#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for(int i = 0; i < section.size(); i++) {
        int d = section[i] + m - 1;
        int cur = i + 1;
        while(1) {
            if(cur == section.size()) break;
            if(section[cur] > d) break;
            cur++;
        }
        i = cur - 1;
        answer++;
    }   
    return answer;
}