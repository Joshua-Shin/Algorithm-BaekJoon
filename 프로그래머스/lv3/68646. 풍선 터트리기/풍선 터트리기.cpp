#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    int lMin[n], rMin[n];
    lMin[0] = a[0]; rMin[n-1] = a[n-1];
    for(int i = 1; i < n; i++) lMin[i] = min(lMin[i-1], a[i]);
    for(int i = n-2; i >= 0; i--) rMin[i] = min(rMin[i+1], a[i]);
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n - 1) {
            answer++;
            continue;
        }
        if(a[i] < lMin[i-1] || a[i] < rMin[i+1]) answer++;
    }
    return answer;
}