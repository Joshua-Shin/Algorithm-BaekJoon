#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[300001];
vector<int> adj[300001];
vector<ll> a;
ll ans;
ll dfs(int x) {
    if(x!=0 && adj[x].size()==1) return a[x];
    for(auto nx: adj[x]) {
        if(p[x]== nx) continue;
        p[nx] = x;
        ll temp = dfs(nx);
        ans += abs(temp);
        a[x] += temp;
    }    
    return a[x];
}
ll solution(vector<int> a, vector<vector<int>> edges) {
    if(accumulate(a.begin(), a.end(), 0ll)) return -1;
    for(auto x: a) ::a.push_back(x);
    for(auto v: edges) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    dfs(0);
    return ans;
}