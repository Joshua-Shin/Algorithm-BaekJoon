#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void postOrder(int st, int en) {
    if(st == en) return;
    if(st == en-1) {
        cout << v[st] << '\n';
        return;
    }
    int idx = st + 1;
    while(idx < en) {
        if(v[st] < v[idx]) break;
        idx++;
    }
    postOrder(st+1, idx);
    postOrder(idx, en);
    cout << v[st] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int num;
    while(cin >> num)
        v.push_back(num);
    postOrder(0, v.size());
    return 0;
}