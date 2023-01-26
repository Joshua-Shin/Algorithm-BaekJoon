#include <bits/stdc++.h>
using namespace std;
const int MX = 100'000 * 10 + 5; // 입력받을 문자열의 최대수 * 문자열의 최대 길이 + 여유분
int nxt[MX][26]; // nxt[5][4] = 6  == 정점번호 5번의 자식노드 중에, 문자 'e'를 숫자로 컨버팅한 값인 4의 정점번호는 6입니다.
bool chk[MX]; // chk[cur] = true == 정점번호 cur이 문자열의 끝입니다.
int root = 1;
int unused = 2; // 정점번호 값. insert 할때 문자 하나 하나 추가할때마다 ++ 됨.
map<string, int> m;
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
    chk[cur] = true;
}
int find(string &s) {
    int cur = root;
    int len = 1;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            return len;
        cur = nxt[cur][c2i(c)];
        len++;
    }
    return len;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    initiate();
    int n;
    cin >> n;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        int len = find(temp);
        string str = temp.substr(0, len);
        if (len - 1 == temp.size() && m[temp] >= 1)
            str += to_string(m[temp]+1);
        ans.push_back(str);
        insert(temp);
        m[temp]++;
    }
    for(auto x: ans) cout << x << '\n';
}