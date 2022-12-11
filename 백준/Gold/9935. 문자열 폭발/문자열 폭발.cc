#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    string str, boom;
    cin >> str >> boom;
    stack <char> st;
    for(int i = 0; i<str.size(); i++) {
        if(str[i]==boom.back()) {
            string temp;
            temp += str[i];
            while(1) {
                if(temp.size()==boom.size()) {
                    reverse(temp.begin(), temp.end());
                    if(temp!=boom) for(auto x: temp) st.push(x);
                    break;
                } 
                if(st.empty()) {
                    reverse(temp.begin(), temp.end());
                    for(auto x: temp) st.push(x);
                    break;
                }
                temp += st.top();
                st.pop();
            }
        }
        else st.push(str[i]);
    }
    string ans;
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if(ans.size()==0) ans = "FRULA";
    cout << ans << '\n';
    return 0;
}