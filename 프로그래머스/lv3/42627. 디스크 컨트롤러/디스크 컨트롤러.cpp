#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> jobs) {
    int totalTime = 0, currentTime = 0, cur = 0;
    sort(jobs.begin(), jobs.end());
    // 최소힙. 소요시간을 앞에다 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(cur < jobs.size() || !pq.empty()) {
        //요청시간이 현재 소요된 시간보다 작을때 작업을 수행할 수 있음
        if(cur < jobs.size() && jobs[cur][0] <= currentTime) {
            pq.push({jobs[cur][1], jobs[cur][0]});
            cur++;
            continue;
        }
        // 수행할 작업이 있어.
        if(!pq.empty()) {
            currentTime += pq.top().first;
            totalTime += currentTime - pq.top().second;
            pq.pop();
        }
        // 수행할 작업이 없고, 현재시간 안에 들어온 작업이 없을 경우 현재시간 조정
        else {
            currentTime = jobs[cur][0];
        }
    }
    return totalTime / jobs.size();
}