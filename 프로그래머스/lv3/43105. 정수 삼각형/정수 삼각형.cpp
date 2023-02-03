#include <bits/stdc++.h>
using namespace std;
int cache[501][501];
int dfs(int x, int y, vector<vector<int>> &triangle) {
    if(x==triangle.size()) return 0;
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    ret = triangle[x][y];
    return ret += max(dfs(x+1, y, triangle), dfs(x+1, y+1, triangle));
}
int solution(vector<vector<int>> triangle) {
    memset(cache, -1, sizeof(cache));
    return dfs(0, 0, triangle);
}