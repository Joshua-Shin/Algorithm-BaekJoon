#include <bits/stdc++.h>
using namespace std;
string b[6] = {"A", "B", "C", "D", "E", "F"};
string convert(int n, int k) {
    string ret;
    while(n) {
        int temp = n % k;
        if(temp >= 10) ret += b[temp-10];
        else ret += to_string(temp);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solution(int n, int t, int m, int p) {
    // 진법, 구할숫자개수, 참가인원, 내순서
    // t * m 길이의 문자열을 구한다음에, answer로 옮기면 되려나..
    string answer = "";
    string str = "0";
    for(int i = 1; ; i++) {
        str += convert(i, n);
        if(str.size() > t * m) break;
    }
    // cout << str << '\n';

    for(int i = p - 1; i < str.size(); i+=m) {
        answer += str[i];
        if(answer.size()==t) break;
    }
    return answer;
}