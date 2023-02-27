#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> answer;
void hanoi(int n, int st, int en) {
    if(n==1) {
        answer.push_back({st, en});
        return;
    }
    hanoi(n-1, st, 6 - st -en);
    answer.push_back({st, en});
    hanoi(n-1, 6-st-en, en);
}
vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3);
    return answer;
}