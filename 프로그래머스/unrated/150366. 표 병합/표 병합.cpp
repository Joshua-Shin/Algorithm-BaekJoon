#include <bits/stdc++.h>
using namespace std;
int p[100001];
string board[3000];
vector<int> adj[3000];
int convertToIdx(int r, int c) {
    return (r-1) * 50 + c;
}
pair<int, int> convertToRC(int idx) {
    return {(idx -1) / 50 + 1, (idx -1) % 50 + 1};
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
vector<string> div(string str) {
    vector<string> ret;
    istringstream ss(str);
    string strBuffer;
    while(getline(ss, strBuffer, ' '))
        ret.push_back(strBuffer);
    return ret;
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 1; i <= 3000; i++) p[i] = i;
    for(auto comm: commands) {
        auto v = div(comm);
        if(v[0] == "UPDATE" && v.size()==4) {
            int idx = convertToIdx(stoi(v[1]), stoi(v[2]));
            board[getParent(idx)] = v[3];
        } else if (v[0] == "UPDATE" && v.size()==3) {
            for(int i = 1; i<=3000; i++) {
                if(board[getParent(i)] != v[1]) continue;
                board[getParent(i)] = v[2];
            }
        } else if (v[0] == "MERGE") {
            int idx1 = convertToIdx(stoi(v[1]), stoi(v[2]));
            int idx2 = convertToIdx(stoi(v[3]), stoi(v[4]));
            if(getParent(idx1) == getParent(idx2)) continue;
            if(board[getParent(idx1)]!="") {
                board[getParent(idx2)] = board[getParent(idx1)];
            } else if(board[getParent(idx2)] != ""){
                board[getParent(idx1)] = board[getParent(idx2)];
            }
            unionParent(idx1, idx2);
        } else if (v[0] == "UNMERGE") {
            int idx = convertToIdx(stoi(v[1]), stoi(v[2]));
            string backup = board[getParent(idx)];
            vector<int> clearList;
            for(int i = 1; i<=3000; i++) {
                if(getParent(i)==getParent(idx)) clearList.push_back(i);
            }
            for(auto i: clearList) {
                p[i] = i;
                board[i] = "";
            }
            board[idx] = backup;
        } else { // PRINT
            int idx = convertToIdx(stoi(v[1]), stoi(v[2]));
            board[getParent(idx)] == "" ? answer.push_back("EMPTY") : answer.push_back(board[getParent(idx)]);
        }
    }
    return answer;
}