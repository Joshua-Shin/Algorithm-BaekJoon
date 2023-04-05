#include <bits/stdc++.h>
using namespace std;
string title[101];
vector<string> div(string str) {
    vector<string> ret;
    istringstream ss(str);
    string strBuffer;
    while(getline(ss, strBuffer, ','))
        ret.push_back(strBuffer);
    return ret;
}
int convert(string a) {
    string hour = a.substr(0, 2);
    string min = a.substr(3, 2);
    return stoi(hour) * 60 + stoi(min);
}
int cal(string a, string b) {
    return convert(b) - convert(a);
}
pair<string, int> go(string m, int idx) {
    string ret;
    vector<string> v = div(m);
    int time = cal(v[0], v[1]);
    int backupTime = time;
    title[idx] = v[2];
    string mel = v[3];
    int cur = 0;
    while(time--) {
        if(cur == mel.size()) cur = 0;
        ret += mel[cur];
        if(cur+1 < mel.size() && mel[cur+1]=='#') {
            ret += '#';
            cur += 2;
        } else {
            cur++;
        }
    }
    return {ret, backupTime};
}
bool isMatch(string pattern, string music, int idx) {
    int findIdx = music.find(pattern, idx);
    if(findIdx == -1) return false;

    int checkIdx = findIdx + pattern.size();
    if(checkIdx < music.size() && music[checkIdx] == '#') {
        return isMatch(pattern, music, checkIdx);
    }
    return true;
    // if(checkIdx == music.size() || music[checkIdx]!='#') return true;
    // return false;
}
bool cmp(vector<int> a, vector<int> b) {
    if(a[0] != b[0]) return a[0] > b[0];
    return a[1] < b[1];
}
string solution(string m, vector<string> musicinfos) {
    // 조건이 일치시, 재생시간이 길고, 먼저 입력된 음악 제목 반환.
    int idx = -1;
    vector<vector<int>> ans; // 재생시간, 입력순서
    for(auto e: musicinfos) {
        idx++;
        string music; int time;
        tie(music, time) = go(e, idx); 
        // cout << "music: " << music << '\n';
        if(isMatch(m, music, 0)) ans.push_back({time, idx});
    }
    if(ans.empty()) return "(None)";
    sort(ans.begin(), ans.end(), cmp);
    return title[ans[0][1]];
}