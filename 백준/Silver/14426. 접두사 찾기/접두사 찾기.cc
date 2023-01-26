#include <bits/stdc++.h>
using namespace std;
const int MX = 10000 * 500 + 5; // 입력받을 문자열의 최대수 * 문자열의 최대 길이 + 여유분
int nxt[MX][26]; // nxt[5][4] = 6  == 정점번호 5번의 자식노드 중에, 문자 'e'를 숫자로 컨버팅한 값인 4의 정점번호는 6입니다.
// bool chk[MX]; // chk[cur] = true == 정점번호 cur이 문자열의 끝입니다.
int root = 1;
int unused = 2; // 정점번호 값. insert 할때 문자 하나 하나 추가할때마다 ++ 됨.
int c2i(char c) {
    return c - 'a';
}
void initiate() {
    memset(nxt, -1, sizeof(nxt));
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
    initiate();
    int n, m;
    cin >> n >> m;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        insert(temp);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if(find(temp)) cnt++;
    }
    cout << cnt;
}