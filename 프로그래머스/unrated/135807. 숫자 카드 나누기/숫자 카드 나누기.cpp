#include <bits/stdc++.h>
using namespace std;
int findGcd(vector<int> &arr) {
    int x = arr[0];
    for(int i = 1; i<arr.size(); i++)
        x = gcd(x, arr[i]);
    return x;
}
bool valid(vector<int> &arr, int num) {
    for(int i = 0; i<arr.size(); i++)
        if(!(arr[i] % num)) return false;
    return true;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int num = findGcd(arrayA);
    if(valid(arrayB, num)) answer = num;
    int num2 = findGcd(arrayB);
    if(valid(arrayA, num2)) answer = max(answer, num2);
    return answer;
}