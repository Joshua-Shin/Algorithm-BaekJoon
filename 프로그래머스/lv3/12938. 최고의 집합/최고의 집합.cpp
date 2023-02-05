#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s) {
        answer.push_back(-1);
        return answer;
    }
    vector<int> ans(n, s / n);
    int b = s % n;
    int i = n-1;
    while(b--) {
        ans[i--]++;
    }
    return ans;
}