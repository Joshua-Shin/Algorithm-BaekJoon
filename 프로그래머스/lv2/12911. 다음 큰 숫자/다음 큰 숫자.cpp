#include <bits/stdc++.h>
using namespace std;
int cntOne(int n) {
    int ret = 0;
    while(n) {
        if(n % 2) ret++;
        n /= 2;
    }
    return ret;
}
int solution(int n) {
    int cntN = cntOne(n);
    for(int i = n +1; ;i++)
        if(cntOne(i)==cntN) return i;
}