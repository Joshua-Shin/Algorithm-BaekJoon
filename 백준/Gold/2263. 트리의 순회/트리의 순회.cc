#include <bits/stdc++.h>
using namespace std;
int n, in[100001], post[100001], inIdx[100001];
void go(int inStart, int inEnd, int postStart, int postEnd) {
    if(inStart >= inEnd || postStart >= postEnd) return;
    int findIdx = inIdx[post[postEnd - 1]];
    int lSize = findIdx - inStart;
    cout << in[findIdx] << ' ';
    go(inStart, findIdx, postStart, postStart + lSize);
    go(findIdx + 1, inEnd, postStart +lSize, postEnd - 1);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        inIdx[in[i]] = i;
    }
    for (int i = 0; i < n; i++) cin >> post[i];
    go(0, n, 0, n);
}