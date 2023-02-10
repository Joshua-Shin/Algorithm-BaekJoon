#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> elements) {
    int n = elements.size();
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n + i; j++) { 
            sum += elements[j % n];
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}