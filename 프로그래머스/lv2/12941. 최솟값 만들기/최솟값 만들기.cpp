#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    return inner_product(A.begin(), A.end(), B.begin(), 0);
}