#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10003];
map<string, int> m; // name to number
map<int, string> m2; // number to name
map<string, int> result; // name, 정산금
int p[10003]; // p[x] = x를 추천한 사람의 번호
bool check[10003];
// 부모 노드 p[x] 갱신용.
void bfs(int x) {
    queue<int> q;
    check[x] = true;
    q.push(x);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        for(auto nx: adj[x]) {
            if(check[nx]) continue;
            check[nx] = true;
            p[nx] = x;
            q.push(nx);
        }
    }
    return;
}
// x 번호 인물에게서 판매수익 profit이 발생했을때 정산 돌리기.
void dfs(int x, int profit) {
    if(m2[x] == "-") return;
    int nx;
    for(auto e: adj[x]) {
        if(p[e]==x) continue; // 현재 leaf 에서 root 로 이동중인데, 역행 방지.
        nx = e; // 자기 부모로 올라가는거임.
    }
    if(profit >= 10) {
        int cal = profit / 10;
        result[m2[x]] += (profit - cal);
        dfs(nx, cal);
    } else result[m2[x]] += profit;
    return;
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    // 민호부터 시작해서 bfs 돌려서 이름 등록하고, 역순으로 해서 순서 파악.
    // 해당 순서 배열에 맞춰 dfs 돌려가며 수익 더해주면 되겠네.
    m["-"] = 1;
    m2[1] = "-";
    // 이름이랑 번호 양방향 맵핑. root가 1 부터 시작
    for(int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = i + 2;
        m2[i+2] = enroll[i];
    }
    for(int i = 0; i < enroll.size(); i++) {
        int a = m[enroll[i]];
        int b = m[referral[i]];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i = 0; i < seller.size(); i++) {
        string name = seller[i];
        int profit = amount[i] * 100;
        dfs(m[name], profit);
    }
    for(int i = 0; i < enroll.size(); i++) {
        answer.push_back(result[enroll[i]]);
    }
    return answer;
}