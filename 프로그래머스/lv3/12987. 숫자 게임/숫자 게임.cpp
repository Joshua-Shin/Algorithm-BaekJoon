#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    // A에서 나오는 수 보다 큰 수중 가장 작은 수.
    // 를 고르면 되는데, 100,000 이기에 이중for문으로는 안돼
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cur1 = 0, cur2 = 0;
    while(cur2 != b.size()) {
        if(a[cur1]>=b[cur2]) {
            cur2++;
        } else if(a[cur1] < b[cur2]) {
            cur1++;
            cur2++;
            answer++;
        }
    }
    return answer;
}