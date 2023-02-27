#include <bits/stdc++.h>
using namespace std;
int dfs(int n) {
    if(n == 0) return 0;
    int temp = n % 10;
    int ret = dfs(n / 10) + temp;
    if(temp >= 5) ret = min(dfs(n / 10 + 1) + (10 - temp), ret);
    return ret;
}
int solution(int storey) {
    int answer = 0;
    answer = dfs(storey);
    return answer;
}