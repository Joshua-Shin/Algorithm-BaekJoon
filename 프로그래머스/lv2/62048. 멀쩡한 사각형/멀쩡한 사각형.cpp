#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int w,int h) {
    int n = gcd(w, h); // 4
    int w2 = w /n; // 2
    int h2 = h/ n; // 3
    int cnt = w2 + (h2 - 1); // 4
    return (ll)w * h - cnt * n; //w*h - 16
}