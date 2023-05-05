#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(string a, string b) {
    if(a[n] != b[n]) return a[n] < b[n];
    return a < b;
}
vector<string> solution(vector<string> strings, int n) {
    ::n = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}

// import java.util.*;
// class Solution {
//     public String[] solution(String[] strings, int n) {
//         Arrays.sort(strings, (s1, s2) 
//                     -> (s1.charAt(n) == s2.charAt(n)) ? s1 - s2 : s1.charAt(n) - s2.charAt(n));
//         return strings;
//     }
// }