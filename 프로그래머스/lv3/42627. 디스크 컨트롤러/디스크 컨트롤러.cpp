#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> jobs) {
    int totalTime = 0;
    sort(jobs.begin(), jobs.end()); // 요청시점, 소요시간
    int currentTime = 0;
    int i = 0;
    // 소요시간, 요청시점
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(i < jobs.size() || !pq.empty()) {
        if(i < jobs.size() && currentTime >= jobs[i][0]) {
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
            continue;
        }
        if(pq.empty()) {
            currentTime = jobs[i][0];
        } else {
            auto [cost, startTime] = pq.top();
            pq.pop();
            currentTime += cost;
            totalTime += currentTime - startTime;
        }
    }
    return totalTime / jobs.size();
}