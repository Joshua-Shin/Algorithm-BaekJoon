#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

void go(int st, int en) {
    if(st + 1 == en) {
        cout << v[st] << ' ';
        return;
    }
    int mid = (st + en) / 2;
    go(st, mid);
    go(mid + 1, en);
    cout << v[mid] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        int temp;
        cin >> temp;
        if(temp == -1) continue;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    go(0, n);
} 