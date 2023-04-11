#include <bits/stdc++.h>
using namespace std;
int go(int st, int en, int w) {
    int diff = en - st + 1;
    int len = w *2 + 1;
    if(diff % len == 0) return diff / len;
    return (diff / len) + 1;
}
int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    
    int st = 1;
    int en = stations[0] - w -1;
    if(st <= en) answer += go(st, en, w);

    for(int i = 0; i<stations.size()-1; i++) {
        int st = stations[i] + w + 1;
        int en = stations[i+1] - w -1;
        if(st > en) continue;
        answer += go(st, en, w);
    }

    st = stations[stations.size()-1] + w + 1;
    en = n;
    if(st <= en) answer += go(st, en, w);

    return answer;

}