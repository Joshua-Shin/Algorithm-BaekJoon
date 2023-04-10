#include <bits/stdc++.h>
using namespace std;
// 1. 가입자 최대한, 2. 판매액 최대한.
int discount[] = {10, 20, 30, 40};
vector<vector<int>> sel;
void go(int cur, int n, vector<int> v) {
    if(cur == n) {
        sel.push_back(v);
        return;
    }
    for(int i = 0; i < 4; i++) {
        v.push_back(discount[i]);
        go(cur + 1, n, v);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    // vector<int> sel;
    // for(int k = 0; k < 4; k++) {
    //     for(int i = 0; i < emoticons.size(); i++) {
    //         sel.push_back(discount[k]);
    //     }
    // }
    // map<string, int> m;
    go(0, emoticons.size(), {});
    int maxCnt = -1;
    int maxCost = -1;
    
    for(int k = 0; k < sel.size(); k++) {
        int cnt = 0;
        int cost = 0;
        for(int i = 0; i < users.size(); i++) {
            int sum = 0;
            for(int j = 0; j < emoticons.size(); j++) {
                if(users[i][0] > sel[k][j]) continue;
                sum += (emoticons[j] * (100 - sel[k][j]) / 100);
                if(sum >= users[i][1]) {
                    break;
                }
            }
            if(sum >= users[i][1]) {
                cnt++;
            } else {
                cost += sum;
            }
        }
        if(maxCnt < cnt) {
            maxCnt = cnt;
            maxCost = cost;
        } else if(maxCnt == cnt) {
            maxCost = max(maxCost, cost);
        }
    }
    return {maxCnt, maxCost};
}