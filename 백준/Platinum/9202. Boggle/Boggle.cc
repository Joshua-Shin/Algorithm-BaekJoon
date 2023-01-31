#include <bits/stdc++.h>
using namespace std;
const int MX = 300'000 * 8 + 5;
int nxt[MX][26];
bool chk[MX];
int root = 1;
int unused = 2;
int findCnt, totalScore, n, m;
string maxLenStr;
vector<string> board;
vector<int> forIniRec;
vector<tuple<int, string, int>> ans;
int c2i(char c) {
    return c - 'A';
}
void initiate() {
    findCnt = totalScore = 0;
    maxLenStr = "";
    board.clear();
    for(auto x: forIniRec) chk[x] = true;
    forIniRec.clear();
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
int calScore(string &s) {
    int len = s.size();
    if(len==8) return 11;
    if(len==7 || len==3) return len-2;
    if(len==6 || len==5 || len==4) return len-3;
    return 0;
}
bool find(string &s) {
    int cur = root;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    if(chk[cur]) {
        forIniRec.push_back(cur);
        chk[cur] = false;
        findCnt++;
        totalScore += calScore(s);
        if(maxLenStr.size() < s.size())
            maxLenStr = s;
        if(maxLenStr.size() == s.size())
            maxLenStr = min(maxLenStr, s);
    }
    return true;
}
bool check[4][4];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
void dfs(int x, int y, string s) {
    s += board[x][y];
    if(s.size() > 8) return;
    if(!find(s)) return;
    for(int k = 0; k<8; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx< 0 || nx >=4 || ny <0 || ny>=4) continue;
        if(check[nx][ny]) continue;
        check[nx][ny] = true;
        dfs(nx, ny, s);
        check[nx][ny] = false;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(nxt, -1, sizeof(nxt));
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        insert(str);
    }
    cin >> m;
    while(m--) {
        initiate();
        for (int i = 0; i < 4; i++) {
            string str;
            cin >> str;
            board.push_back(str);
        }
        for(int i = 0; i< 4; i++) {
            for(int j = 0; j<4; j++) {
                memset(check, false, sizeof(check));
                check[i][j] = true;
                dfs(i, j, "");
            }
        }
        ans.push_back({totalScore, maxLenStr, findCnt});
    }
    for(auto [a, b, c]: ans)
        cout << a << ' ' << b << ' '<< c << '\n';
}