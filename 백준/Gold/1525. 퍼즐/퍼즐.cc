#include <bits/stdc++.h>
using namespace std;
string st, en = "123456780";
set <string> s;
map <string, int> cnt;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int bfs() {
    s.insert(st);
    cnt[st] = 0;
    queue<string> q;
    q.push(st);
    while(!q.empty()) {
        string cur = q.front();
        if(cur == en) return cnt[cur];
        q.pop();
        int idx = cur.find('0');
        int x = idx / 3;
        int y = idx % 3;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nIdx = nx * 3 + ny;
            if(nx < 0 || 3 <= nx || ny < 0 || 3 <= ny) continue;
            string nCur = cur;
            swap(nCur[idx], nCur[nIdx]);
            if(s.find(nCur) != s.end()) continue;
            s.insert(nCur);
            cnt[nCur] = cnt[cur] + 1;
            q.push(nCur);
        }
    }
    return -1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) {
            int temp;
            cin >> temp;
            st += to_string(temp);
        }
    cout << bfs();
}