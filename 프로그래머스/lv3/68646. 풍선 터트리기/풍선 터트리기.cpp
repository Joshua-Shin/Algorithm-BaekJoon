#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a) {
    int answer = 1;
    // 가장 작은 수를 기준으로 오른쪽 왼쪽을 나눠.
    // 오른쪽에서 한칸씩 가면서, 남아있는 중 가장 작은 수...
    int minValue = 2e9;
    int minIdx;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < minValue) {
            minValue = a[i];
            minIdx = i;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = a.size()-1; i !=minIdx; i--) {
        pq.push(a[i]);
        if(pq.top() == a[i]) answer++;
    }
    priority_queue<int, vector<int>, greater<int>> pq2;
    for(int i = 0; i !=minIdx; i++) {
        pq2.push(a[i]);
        if(pq2.top() == a[i]) answer++;
    }
    return answer;
}