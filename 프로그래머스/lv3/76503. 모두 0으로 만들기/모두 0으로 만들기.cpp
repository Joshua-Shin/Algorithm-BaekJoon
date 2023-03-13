#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[300001]; // p[x] : x의 부모노드 반환.
int lc[300001];
int rc[300001];
vector<int> adj[300001];
vector<ll> a;
ll ans;
// 부모노드랑 자식 노드 갱신
void dfs(int x) { 
    for(auto nx: adj[x]) {
        if(p[x] == nx) continue;
        p[nx] = x;
        if(lc[x]== -1) lc[x] = nx;
        else rc[x] = nx;
        dfs(nx);
    }
}
ll dfs2(int x) {
    if(lc[x]==-1 && rc[x]==-1)
        return a[x];
    for(auto nx: adj[x]) {
        if(p[x]== nx) continue;
        ll temp = dfs2(nx);
        ans += abs(temp);
        a[x] += temp;
    }    
    return a[x];
}
ll solution(vector<int> a, vector<vector<int>> edges) {
    ll sum = 0;
    for(auto x: a) sum += x;
    if(sum != 0) return -1;

    for(auto x: a) ::a.push_back(x);

    for(auto v: edges) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    dfs(0);
    dfs2(0);
    return ans;
}