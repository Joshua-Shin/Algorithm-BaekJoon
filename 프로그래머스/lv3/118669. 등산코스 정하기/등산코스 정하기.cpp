#include <bits/stdc++.h>
#define MAX 50001
using namespace std;
vector<int> res; // 산봉우리 번호, intensity
vector<pair<int, int>> adj[MAX];
int intensity[MAX]; //  출입구 A에서 출발하여 i번 지점까지 올 때 가능한 최소 intensity(=등산로들의 가중치 중 최댓값)
bool isSummit[MAX];
void go(vector<int>& gates) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> temp;
    memset(intensity, -1, sizeof(intensity));
    for(auto g : gates) {
        pq.push({0, g});
        intensity[g] = 0;
    }
    while(!pq.empty()) {
        int cost = pq.top().first; // 여기에서 cost는 지금까지 이동해온 최소 경로중 가장 큰 가중치.
        int nowV = pq.top().second;
        pq.pop();
        
        // if(cost > intensity[nowV]) continue;
        
        // 아, 산봉우리에 도착한 순간을 이제 temp에 넣는거네.
        if(isSummit[nowV]) {
            temp.push_back({cost, nowV});
            continue;
        }
        
        for(auto p : adj[nowV]) {
            int weight = p.first;
            int to = p.second;
            
            if(intensity[to] == -1 || max(cost, weight) < intensity[to]) {
                intensity[to] = max(cost, weight);
                pq.push({intensity[to], to});
            }
        }
    }
    
    sort(temp.begin(), temp.end());
    res.push_back(temp[0].second);
    res.push_back(temp[0].first);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for (auto e : paths) {
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }
    for(auto s : summits) isSummit[s] = true;
    go(gates);
    return res;
}