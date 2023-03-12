#include <bits/stdc++.h>
using namespace std;
string ans;
int n, m, r, c, k;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'d', 'l', 'r', 'u'}; // 사전순 : d l r u
void dfs(int x, int y, string path) {
    if(path.size() == k) {
        if(x == r && y == c)
            if(ans=="" || ans > path) ans = path;
        return;
    }
    int diff = ::k - path.size();
    int dist = abs(x-r) + abs(y-c);
    if(dist > diff) return;
    
    for(int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        string nPath = path + dir[k];
        int diff = ::k - nPath.size();
        string availPath = nPath;
        while(diff--) availPath += 'd';
        if(ans!= "" && availPath >= ans) continue;
        dfs(nx, ny, nPath);
    }
    return;
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    x--, y--, r--, c--;
    ::n = n; ::m = m; ::r = r; ::c=c; ::k=k;
    if((abs(x-r) + abs(y-c)) % 2 != k % 2) return "impossible";
    dfs(x, y, "");
    if(ans.size()==0) return "impossible";
    return ans;
}