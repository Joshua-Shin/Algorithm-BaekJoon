#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            char op;
            int num;
            cin >> op >> num;
            if(op=='I') m[num]++;
            else {
                if(m.size()==0) continue;
                else if(num==-1) {
                    if(m.begin()->second==1) {
                        m.erase(m.begin());
                    }
                    else {
                        m[m.begin()->first]--;
                    }
                }
                else {
                    auto it = m.end();
                    it--;
                    if(it->second==1) {
                        m.erase(it);
                    }
                    else {
                        m[it->first]--;
                    }
                }
            }
        }
        if(m.size()==0) {
            cout << "EMPTY" << '\n';
            continue;
        }
        else {
            auto it = m.end();
            it--;
            cout << (it)->first << ' ' << m.begin() -> first << '\n';
        }
    }
    return 0;
}