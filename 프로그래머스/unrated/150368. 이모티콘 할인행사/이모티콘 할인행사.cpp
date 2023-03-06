#include <bits/stdc++.h>
using namespace std;
vector<int> sales = {10, 20, 30, 40};
vector<vector<int>> users;
vector<int> emoticons;
int maxCostSum, maxCnt;
void dfs(vector<pair<int, int>> arr) { // 원가, 할인율
    if(arr.size() == emoticons.size()) {
        int costSum = 0;
        int cnt = 0;
        for(int i = 0; i<users.size(); i++) {
            int cost = 0;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[j].second < users[i][0]) continue;
                cost += ((arr[j].first / 100) * (100 - arr[j].second));
                if(cost >= users[i][1]) {
                    cost = 0;
                    cnt++;
                    break;
                }
            }
            costSum += cost;
        }
        if(maxCnt < cnt) {
            maxCnt = cnt;
            maxCostSum = costSum;
        } else if(maxCnt == cnt && maxCostSum < costSum) {
            maxCostSum = costSum;
        }
        return;
    }
    int cur = arr.size();
    for(int j = 0; j < 4; j++) {
        arr.push_back({emoticons[cur], sales[j]});
        dfs(arr);
        arr.pop_back();
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<pair<int, int>> arr; // 원가, 할인율
    ::users = users;
    ::emoticons = emoticons;
    dfs(arr);
    return {maxCnt, maxCostSum};
}