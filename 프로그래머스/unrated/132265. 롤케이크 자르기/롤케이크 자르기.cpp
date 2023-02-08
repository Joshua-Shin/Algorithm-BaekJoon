#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    for(int i = 0; i<topping.size(); i++) m2[topping[i]]++;
    for(int i = 0; i<topping.size(); i++) {
        m1[topping[i]]++;
        m2[topping[i]]--;
        if(!m2[topping[i]]) m2.erase(topping[i]);
        if(m1.size()==m2.size()) answer++;
    }
    return answer;
}