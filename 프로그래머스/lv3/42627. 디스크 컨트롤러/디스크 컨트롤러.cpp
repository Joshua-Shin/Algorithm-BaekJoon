#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> jobs) {
    int totalTime = 0, cur = 0, currentTime = 0;
    sort(jobs.begin(), jobs.end());
    // 소요시간, 요청시각
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(cur < jobs.size() || !pq.empty()) {
        if(cur < jobs.size() && currentTime >= jobs[cur][0]) {
            pq.push({jobs[cur][1], jobs[cur++][0]});
            continue;
        }
        if(!pq.empty()) {
            auto [cost, requestTime] = pq.top();
            pq.pop();
            currentTime += cost;
            totalTime += (currentTime - requestTime);
        } else currentTime = jobs[cur][0];
    }
    return totalTime / jobs.size();
}