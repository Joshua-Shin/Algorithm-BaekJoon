#include <bits/stdc++.h>
using namespace std;
int n;
int arr[140000];
vector<int> ans;
void go(int st, int en) {
    if(st >= en) return;
    // if(st == en -1) {
    //     ans.push_back(arr[st]);
    //     return;
    // }
    int mid = (st + en) /2;
    go(st, mid);
    go(mid+1, en);
    ans.push_back(arr[mid]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int hideIdx;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == -1) hideIdx = i;
    }
    cin >> arr[hideIdx];
    sort(arr, arr+n);
    go(0, n);
    for(auto x: ans) cout << x << ' ';
}