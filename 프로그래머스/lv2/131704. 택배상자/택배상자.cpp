#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    // vector<int> box(order.size());
    // for(int i = 0; i<box.size() i++) box[i] = i + 1;
    stack <int> st;
    int cur = 0;
    for(int i = 1; i <= order.size(); i++) {
        if(order[cur] == i) {
            cur++;
            while(!st.empty()) {
                if(order[cur] != st.top()) break;
                st.pop();
                cur++;
            }
        }
        else if(order[cur] != i) st.push(i);
    }
    return cur;
}