#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> st;
    for(int i = 0; i<numbers.size(); i++) {
        while(!st.empty()) {
            auto [a, b] = st.top();
            if(numbers[i] <= a) break;
            answer[b] = numbers[i];
            st.pop();
        }
        st.push({numbers[i], i});
    }
    return answer;
}