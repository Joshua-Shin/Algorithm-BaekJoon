#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> arr) {
    int answer = 1;
    for(auto x: arr)
        answer = lcm(x,answer);
    return answer;
}