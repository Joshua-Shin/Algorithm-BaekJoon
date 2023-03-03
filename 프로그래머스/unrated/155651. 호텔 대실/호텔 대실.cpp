#include <bits/stdc++.h>
using namespace std;
int convertToInt(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    return hour * 60 + minute;
}
int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> v;
    for (vector<string> time : book_time) {
        int start = convertToInt(time[0]);
        int end = convertToInt(time[1]) + 10;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> room;
    room.push(v[0].second);
    for(int i = 1; i < v.size(); i++) {
        if(v[i].first < room.top()) room.push(v[i].second);
        else {
            room.pop();
            room.push(v[i].second);
        }
    }
    return room.size();
}