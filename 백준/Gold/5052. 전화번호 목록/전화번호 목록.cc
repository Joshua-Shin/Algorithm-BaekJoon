#include <bits/stdc++.h>
using namespace std;
const int MX = 10000 * 10 + 5; // 입력받을 문자열의 최대수 * 문자열의 최대 길이 + 여유분
int nxt[MX][10]; // nxt[5][4] = 6  == 정점번호 5번의 자식노드 중에, 문자 'e'를 숫자로 컨버팅한 값인 4의 정점번호는 6입니다.
// bool chk[MX]; // chk[cur] = true == 정점번호 cur이 문자열의 끝입니다.
int root = 1;
int unused = 2; // 정점번호 값. insert 할때 문자 하나 하나 추가할때마다 ++ 됨.
int c2i(char c) {
    return c - '0';
}
void initiate() {
    memset(nxt, -1, sizeof(nxt));
    unused = 2;
}
void insert(string &s) {
    int cur = root;
    for(auto c : s) {
        if(nxt[cur][c2i(c)] == -1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    // chk[cur] = true;
}
bool find(string &s) {
    int cur = root;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc, n;
    cin >> tc;
    vector<string> ans;
    while(tc--) {
        initiate();
        cin >> n;
        vector<string> inputS(n);
        for (int i = 0; i < n; i++) cin >> inputS[i];
        sort(inputS.begin(), inputS.end());
        reverse(inputS.begin(), inputS.end());
        for(auto s: inputS) {
            if(find(s)) {
                ans.push_back("NO");
                goto out;
            }
            insert(s);
        }
        ans.push_back("YES");
        out:;
    }
    for(auto x: ans) cout << x << '\n';
}