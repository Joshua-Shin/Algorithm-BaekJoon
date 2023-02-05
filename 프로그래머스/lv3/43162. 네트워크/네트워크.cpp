#include <bits/stdc++.h>
using namespace std;
vector<int> adj[201];
bool check[201];
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
            q.push(nx);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(i==j) continue;
            if(computers[i][j]) adj[i].push_back(j);
        }
    }
    for(int i = 0; i<n; i++) {
        if(!check[i]) {
            bfs(i);
            answer++;
        }
    }
    return answer;
}