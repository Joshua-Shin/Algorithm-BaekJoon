#include <bits/stdc++.h>
using namespace std;
int n;
const int MX = 100'001;
int in[MX], post[MX], inIdx[MX];
void preOrder(int inSt, int inEn, int postSt, int postEn) {
    if(inSt >= inEn || postSt >= postEn) return;
    int rootIdx = inIdx[post[postEn -1]];
    cout << in[rootIdx] << ' ';
    int length = rootIdx - inSt;
    preOrder(inSt, rootIdx, postSt, postSt + length);
    preOrder(rootIdx +1, inEn, postSt + length, postEn-1);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        inIdx[in[i]] = i;
    }
    for (int i = 0; i < n; i++) cin >> post[i];
    preOrder(0, n, 0, n);
}