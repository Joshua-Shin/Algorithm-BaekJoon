#include <bits/stdc++.h>
using namespace std;
const int ROOT = 1;
int unused = 2; // root는 비워두고 2번 정점부터 입력 넣을거임.
const int MX = 10000 * 500 + 5; // 입력 받을 문자열의 최대 수 * 문자열의 최대길이 + 알파
bool chk[MX]; // true라면, 단어의 마지막 문자임.
int nxt[MX][26]; // nxt[x][y] = 현 위치가 x 일때, 문자 c를 c2i로 변환한 값 y의 정점 번호. (단, -1일 경우 해당 정점이 없다는뜻)
int c2i(char c) { // 문자를 배열 인덱스 데이터로 여기기 위해 문자를 정수로 변환하는 함수
    return c - 'A';
}
void insert(string &s) {
    int cur = ROOT;
    for(auto c : s) {
        if(nxt[cur][c2i(c)]==-1)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = true;
}
bool find(string &s) {
    int cur = ROOT;
    for(auto c : s) {
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}
void erase(string &s) {
    int cur = ROOT;
    for(auto c : s) {
        if(nxt[cur][c2i(c)]==-1)
        return;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(nxt, -1, sizeof(nxt));
    return 0;
}