#include <bits/stdc++.h>
using namespace std;
const int MX = 10'000'001;
int cnt[MX]; // cnt[x] : x 번호 귤의 개수를 반환
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(auto x: tangerine) cnt[x]++;
    sort(cnt, cnt+MX);
    reverse(cnt, cnt+MX);
    for(int i = 0; i<MX; i++) {
        k -= cnt[i];
        answer++;
        if(k <= 0) return answer;
    }
}