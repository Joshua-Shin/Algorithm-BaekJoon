#include <bits/stdc++.h>
using namespace std;
int col;
bool cmp(vector<int> a, vector<int> b) {
    if(a[col-1] != b[col-1]) return a[col-1] < b[col-1];
    return a[0] > b[0];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    ::col = col;
    sort(data.begin(), data.end(), cmp);
    vector<int> v;
    for(int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for(int j = 0; j<data[0].size(); j++)
            sum += data[i-1][j] % i;
        v.push_back(sum);
    }
    int st = v[0];
    for(int i = 1; i< v.size(); i++) {
        st = st ^ v[i];
    }
    return st;
}