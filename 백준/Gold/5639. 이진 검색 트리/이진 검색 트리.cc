#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void postOrder(int root, int end) {
    if(root == end) return;
    if(root == end -1) {
        cout << v[root] << '\n';
        return;
    }
    int cur = root + 1;
    while(cur < end) {
        if(v[root] < v[cur]) break;
        cur++;
    }
    postOrder(root + 1, cur);
    postOrder(cur, end);
    cout << v[root] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int num;
    while(cin>>num)
        v.push_back(num);
    postOrder(0, v.size());
    return 0;
}