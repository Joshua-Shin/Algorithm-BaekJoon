#include <bits/stdc++.h>
using namespace std;
const int MX = 1000;
int nxt[MX][2], root = 1, unused =2, n;
bool chk[MX], success;
vector<pair<int, int>> v;
map<int, string> m, m2;
int c2i(char c) {
    return c - '0';
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
bool find(string &s) {
    int cur = root;
    for(auto c: s) {
        if(nxt[cur][c2i(c)] == -1)
            return false;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
string successStr;
void join(int len, string s) {
    if(success) return;
    if(s.size()==len) {
        insert(s);
        success = true;
        successStr = s;
    }
    string s2 = s + '0';
    if(!find(s2)) join(len, s2);
    if(success) return;
    string s3 = s + '1';
    if(!find(s3)) join(len, s3);
    return;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    initiate();
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back({temp, i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i<v.size(); i++) { 
        int len = v[i].first;
        success = false;
        join(len, "");
        if(!success) {
            cout << -1;
            return 0;
        }
        m2[v[i].second] = successStr;
    }
    cout << 1 << '\n';
    for(int i = 0; i<n; i++)
        cout << m2[i] << '\n';
}