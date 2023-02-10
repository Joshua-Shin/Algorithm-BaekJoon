#include <bits/stdc++.h>
using namespace std;
string solution(int n) {
    string answer = "";
    while(n) {
        int remain = n % 3;
        n /= 3;
        if(!remain) {
            n--;
            answer = '4' + answer;
        }
        else answer = to_string(remain) + answer;
    }
    return answer;
}