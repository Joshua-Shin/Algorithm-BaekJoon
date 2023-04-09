#include <bits/stdc++.h>
using namespace std;
vector<int> answer;
int maxScore = -1;
int scores[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int cal(vector<int> &v, vector<int> &info) {
    int score1 = 0, score2 = 0;
    for(int i = 0; i< 11; i++) {
        if(v[i] > info[i]) score1 += scores[i];
        else if(info[i] > 0) score2 += scores[i];
    }
    return score1 - score2;
}
bool isPriority(vector<int> &v, vector<int> &answer) {
    for(int i = 10; i >= 0; i--) {
        if(v[i] == answer[i]) continue;
        if(v[i] > answer[i]) return true;
        else return false;
    }
    return true;
}
void go(int n, int cur, vector<int> v, vector<int> &info) {
    if(n == 0 || cur == v.size()) {
        if(n != 0) v[v.size()-1] += n;
        int score = cal(v, info);
        if(score <= 0) return;
        if(maxScore < score) {
            // cout << "=============" << '\n';
            // cout << score << '\n';
            // for(auto x: v) cout << x << ' ';
            // cout << "=============" << '\n';

            maxScore = score;
            answer = v;
            return;
        } 
        if(maxScore == score) {
            if(isPriority(v, answer)) answer = v;
            // cout << score << '\n';
            return;
        }
        return;
    }
    // 화살 안쏨
    go(n, cur+1, v, info);
    // 화살 쏨
    if(n > info[cur]) {
        v[cur] = info[cur] + 1;
        go(n-info[cur]-1, cur+1, v, info);
    }
    return;
}
vector<int> solution(int n, vector<int> info) {
    // 아예 안맞추거나 어피치가 맞춘 갯수보다 한개 더 맞추거나 해서
    // 어피치와의 점수차를 계산 후, 이전 기록보다 좋으면 갱신하고 아니면 갱신 안하고.
    // 다만 화살수가 남았을 경우 0점에다가 몰아 쏘면 되지 않을까.
    vector<int> v(11, 0);
    go(n, 0, v, info);
    if(maxScore == -1) return {-1};
    return answer;
}