#include <bits/stdc++.h>
using namespace std;
string solution(int n) {
    string answer = "";
    while(n) {
        int temp = n % 3;
        n /= 3;
        if(temp) answer = to_string(temp) + answer;
        else {
            answer = '4' + answer;
            n--;
        }
       
    }
    return answer;
}