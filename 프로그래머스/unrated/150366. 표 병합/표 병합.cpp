#include <bits/stdc++.h>
using namespace std;
int p[100001];
string board[53][53];
vector<int> adj[3000];
bool check[3000];
int convertToIdx(int r, int c) {
    return (r-1) * 50 + c;
}
pair<int, int> convertToRC(int idx) {
    int r = (idx -1) / 50 + 1;
    int c = (idx -1) % 50 + 1;
    return {r, c};
}
int getParent(int x) {
    if (p[x] == x) return x;
    return p[x] = getParent(p[x]);
}
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x < y) p[y] = x;
    else p[x] = y;
}
bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}
void initiateParentTable(int n) {
    for (int i = 1; i <= n; i++)
        p[i] = i;
}

vector<string> div(string str) {
    vector<string> ret;
    istringstream ss(str);
    string strBuffer;
    while(getline(ss, strBuffer, ' '))
        ret.push_back(strBuffer);
    return ret;
}
void update(int r, int c, string value) {
    board[r][c] = value;
    int idx = convertToIdx(r, c);
    queue<int> q;
    memset(check, false, sizeof(check));
    check[idx] = true;
    q.push(idx);
    while(!q.empty()) {
        idx = q.front();
        q.pop();
        for(auto nIdx : adj[idx]) {
            if(check[nIdx]) continue;
            check[nIdx] = true;
            auto e = convertToRC(nIdx); // 103넘기면 왜 11, 3 ??
            board[e.first][e.second] = value;
            q.push(nIdx);
        }
    }
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    initiateParentTable(3000);
    for(auto comm: commands) {
        auto v = div(comm);
        if(v[0] == "UPDATE" && v.size()==4) {
            update(stoi(v[1]), stoi(v[2]), v[3]);
        } else if (v[0] == "UPDATE" && v.size()==3) {
            for(int i = 1; i <= 50; i++) {
                for(int j = 1; j <= 50; j++) {
                    if(board[i][j] != v[1]) continue;
                    board[i][j] = v[2];
                }
            }
        } else if (v[0] == "MERGE") {
            int r1 = stoi(v[1]); int c1 = stoi(v[2]);
            int r2 = stoi(v[3]); int c2 = stoi(v[4]);
            int idx1 = convertToIdx(r1, c1);
            int idx2 = convertToIdx(r2, c2);
            if(isSameParent(idx1, idx2)) continue;
            if(board[r1][c1]!="") {
                update(r2, c2, board[r1][c1]);
            } else if(board[r2][c2] != ""){
                update(r1, c1, board[r2][c2]);
            }
            // 병합
            adj[idx1].push_back(idx2);
            adj[idx2].push_back(idx1);
            unionParent(idx1, idx2);
        } else if (v[0] == "UNMERGE") {
            int r = stoi(v[1]);
            int c = stoi(v[2]);
            string backup = board[r][c];
            int idx = convertToIdx(r, c);
            queue<int> q;
            vector<int> node;
            memset(check, false, sizeof(check));
            check[idx] = true;
            node.push_back(idx);
            q.push(idx);
            while(!q.empty()) {
                idx = q.front();
                q.pop();
                for(auto nIdx: adj[idx]) {
                    if(check[nIdx]) continue;
                    check[nIdx] = true;
                    q.push(nIdx);
                    node.push_back(nIdx);
                }
            }
            for(auto e: node) {
                p[e] = e;
                adj[e].clear();
                auto p = convertToRC(e);
                int er = p.first;
                int ec = p.second; 
                board[er][ec] = "";
            }
            board[r][c] = backup;
        } else { // PRINT
            int r = stoi(v[1]);
            int c = stoi(v[2]);
            board[r][c] == "" ? answer.push_back("EMPTY") : answer.push_back(board[r][c]);
        }
        // cout << "  1 2 3 4 5" << '\n';
        // for(int i = 1; i<=5; i++) {
        //     cout << i << ' ';
        //     for(int j = 1; j<=5; j++) {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    return answer;
}