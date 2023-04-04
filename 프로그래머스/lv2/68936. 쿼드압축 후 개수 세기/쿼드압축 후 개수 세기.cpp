#include <bits/stdc++.h>
using namespace std;
int zero, one;
void go(vector<vector<int>> &arr) {
    int n = arr.size();
    // 기저사례
    int t = arr[0][0];
    bool flag = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] != t) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag) {
        if(t==1) one++;
        else zero++;
        return;
    }

    // 분할
    vector<vector<int>> nArr(n/2, vector<int>(n/2, 0));
    for(int i = 0; i < n /2; i++) {
        for(int j = 0; j< n/2; j++) {
            nArr[i][j] = arr[i][j];
        }
    }
    go(nArr);
    for(int i = n/2; i < n; i++) {
        for(int j = 0; j< n/2; j++) {
            nArr[i - n/2][j] = arr[i][j];
        }
    }
    go(nArr);
    for(int i = 0; i < n /2; i++) {
        for(int j = n/2; j< n; j++) {
            nArr[i][j-n/2] = arr[i][j];
        }
    }
    go(nArr);
    for(int i = n/2; i < n; i++) {
        for(int j = n/2; j< n; j++) {
            nArr[i-n/2][j-n/2] = arr[i][j];
        }
    }
    go(nArr);
    return;
}
vector<int> solution(vector<vector<int>> arr) {
    go(arr);
    return {zero, one};
}