#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    vector<int> v;
    elements.insert(elements.end(), elements.begin(), elements.end());
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) 
                sum += elements[j];
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v.size();
}