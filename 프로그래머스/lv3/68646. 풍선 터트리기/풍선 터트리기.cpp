#include <bits/stdc++.h>
using namespace std;
const int MX = 1'000'000;
int solution(vector<int> a) {
    int answer = 0;
    int lMin[MX], rMin[MX];
    lMin[0] = a[0];
    for(int i = 1; i < a.size(); i++)
        lMin[i] = min(lMin[i-1], a[i]);
    rMin[a.size()-1] = a[a.size()-1];
    for(int i = a.size()-2; i >= 0; i--)
        rMin[i] = min(rMin[i+1], a[i]);
    for(int i = 0; i < a.size(); i++) {
        if(i == 0 || i == a.size()-1) {
            answer++;
            continue;
        }
        if(a[i] < lMin[i-1] || a[i] < rMin[i+1])
            answer++;
    }
    return answer;
}