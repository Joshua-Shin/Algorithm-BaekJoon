#include <bits/stdc++.h>
using namespace std;
int n;
bool check[105];
bool check2[105];
int dfs(int cur, vector<int> &cards) {
    if(check[cur]) return 0;
    check[cur] = true;
    int nCur = cards[cur] - 1;
    return dfs(nCur, cards) + 1;
}
int solution(vector<int> cards) {
    n = cards.size();
    int answer = 0;
    for(int i = 0; i < n; i++) { // 첫 선택 인덱스
        memset(check, false, sizeof(check));
        int result1 = dfs(i, cards);
        int result2 = 0;
        for(int j = 0; j < n; j++) { // 두번째 선택 인덱스
            if(i == j) continue;
            if(check[j]) continue;
            result2 = max(result2, dfs(j, cards));
        }
        answer = max(answer, result1 * result2);
    }
    return answer;
}