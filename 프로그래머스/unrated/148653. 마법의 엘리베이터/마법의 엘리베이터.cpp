#include <bits/stdc++.h>
using namespace std;
int dfs(int n) {
    if(n < 10) return min(n, 10 -n + 1);
    int temp = n % 10;
    return min(dfs(n / 10 + 1) + (10 - temp), dfs(n / 10) + temp);
}
int solution(int storey) {
    int answer = 0;
    answer = dfs(storey);
    return answer;
}