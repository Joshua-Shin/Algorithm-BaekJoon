#include <bits/stdc++.h>
using namespace std;
bool isAvailable(int num, vector<int> stones, int k) {
    int cnt = 0;
    for(int i = 0; i<stones.size(); i++) {
        if(stones[i] - num < 0) cnt++;
        else cnt = 0;
        if(cnt >= k) return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int left = 0;
    int right = 2e9;
    // int right = 10;
    int answer = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(isAvailable(mid, stones, k)) {
            left = mid + 1;
            answer = max(answer, mid);
        } else {
            right = mid - 1;
        }
    }
    return answer;
}