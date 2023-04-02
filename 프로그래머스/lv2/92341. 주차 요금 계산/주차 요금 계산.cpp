#include <bits/stdc++.h>
using namespace std;
int convert(string s) {
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    return hour * 60 + min;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // 차량번호별 누적시간 계산하면 되겠네 그냥. 어떤 자료구조를 쓸까.
    stack<int> st[10000];
    int totalTime[10000];
    vector<int> carNum;
    for(auto r: records) {
        int time = convert(r.substr(0, 5));
        int number = stoi(r.substr(6, 4));
        if(st[number].empty()) st[number].push(time);
        else {
            totalTime[number] += time - st[number].top();
            st[number].pop();
        }
        carNum.push_back(number);
    }
    sort(carNum.begin(), carNum.end());
    carNum.erase(unique(carNum.begin(), carNum.end()), carNum.end());
    for(auto n: carNum) {
        if(!st[n].empty())
            totalTime[n] += (convert("23:59") - st[n].top());
    }
    for(auto n: carNum) {
        int cost;
        if(totalTime[n] <= fees[0]) cost = fees[1];
        else cost = fees[1] + ceil((double)(totalTime[n] - fees[0]) / fees[2]) * fees[3];
        answer.push_back(cost);
    }
    return answer;
}