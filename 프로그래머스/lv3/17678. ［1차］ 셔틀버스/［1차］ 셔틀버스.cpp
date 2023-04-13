#include <bits/stdc++.h>
using namespace std;
// 마지막 셔틀 시간을 확인하고,
// 해당 셔틀시간에 타는 애중 가장 마지막 타임인애보다 1분 먼저 오면 되잖아.
int convert(string s) {
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3));
    return hour * 60 + min;
}
string convert2(int time) {
    string ret;
    int hour = time / 60;
    int min = time % 60;
    if(hour < 10) ret += '0';
    ret += to_string(hour);
    ret += ':';
    if(min < 10) ret += '0';
    ret += to_string(min);
    return ret;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    for(auto e: timetable) {
        v.push_back(convert(e));
    }
    sort(v.begin(), v.end());

    int cur = 0;
    for(int time = 540; time < 24 * 60 && time <= 540 + (n-1) * t; time += t) {
        int cnt = 0;
        if(time == 540 + (n-1) * t) {
            for(int i = cur; i < v.size(); i++) {
                if(v[i] <= time) {
                    cnt++;
                    if(cnt == m) return convert2(v[i]-1);
                } else break;
            }
            return convert2(time);
        }
        for(int i = cur; i < v.size(); i++) {
            if(v[i] <= time) {
                cnt++;
                if(cnt == m) {
                    cur = i + 1;                    
                    break;
                }
            }
            else {
                cur = i;
                break;
            }
        }
    }
    return answer;
}