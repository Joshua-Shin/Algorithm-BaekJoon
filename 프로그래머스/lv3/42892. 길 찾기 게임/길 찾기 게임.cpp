#include <bits/stdc++.h>
using namespace std;
int lc[10001];
int rc[10001];
map<vector<int>, int> m; // nodeinfo --> nodeNum
map<int, vector<int>> m2; // nodeNum --> nodeinfo
int root;
vector<int> v1, v2;
bool cmp(vector<int> a, vector<int> b) { // y값 내림차순, x값 오름차순
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] < b[0];
}
void preOrder(int node) {
    v1.push_back(node);
    if(lc[node] != 0) preOrder(lc[node]);
    if(rc[node] != 0) preOrder(rc[node]);
    return;
}
void postOrder(int node) {
    if(lc[node] != 0) postOrder(lc[node]);
    if(rc[node] != 0) postOrder(rc[node]);
    v2.push_back(node);
    return;
}
void go(int node, int cur, int st, int en, vector<vector<int>> &nodeinfo) {
    // ny가  y 값보다 작고,
    // st <= nx < x값 이면 lc[node] =
    // x값 < nx <= en rc[node] = 
    int x = m2[node][0];
    int y = m2[node][1];
    int idx1, idx2;
    for(int i = cur + 1; i < nodeinfo.size(); i++) {
        int nx = nodeinfo[i][0];
        int ny = nodeinfo[i][1];
        if(ny == y) continue;
        if(nx >= x) break;
        if(st <= nx && nx < x) {
            lc[node] = m[{nx, ny}];
            idx1 = i;
            break;
        }
    }
    for(int i = cur + 1; i < nodeinfo.size(); i++) {
        int nx = nodeinfo[i][0];
        int ny = nodeinfo[i][1];
        if(ny == y) continue;
        if(nx >= en) break;
        if(x < nx && nx < en) {
            rc[node] = m[{nx, ny}];
            idx2 = i;
            break;
        }
    }
    // cout << "root: " << node << " lc[node]: " << lc[node] << '\n';
    // cout << "root: " << node << " rc[node]: " << rc[node] << '\n';
    if(lc[node] != 0) go(lc[node], idx1, st, x, nodeinfo);
    if(rc[node] != 0) go(rc[node], idx2, x+1, en, nodeinfo);
    
    
    
    
    
    
    // int level = 0;
    // for(int i = cur+1; i < nodeinfo.size(); i++) {
    //     int nx = nodeinfo[i][0];
    //     int ny = nodeinfo[i][1];
    //     if(st <= nx && nx < x) {
    //         vector<int> v = {nx, ny}; // 
    //         lc[node] = m[v]; // 이게 가능한가?
    //         // level = ny;
    //         // cout << "root: " << node << " lc[node]: " << lc[node] << '\n';
    //         go(lc[node], i, st, x, nodeinfo); 
    //     }
    //     if(x < nx && nx < en) {
    //         // lc를 찾았다면, level이 같아야 하는데 더 깊이 들어가서 찾고 있다면 그건 실패한 탐식이니 return.
    //         /// 왼쪽자식과 오른쪽자식의 높이가 동일하다는 조건은 없었는데????????
    //         // if(lc[node]!=0 && ny != level) return; 
    //         vector<int> v = {nx, ny};
    //         rc[node] = m[v];
    //         // cout << "root: " << node << " rc[node]: " << rc[node] << '\n';
    //         go(rc[node], i, x + 1, en, nodeinfo); 
    //         return;
    //         // 하나라도 rc를 찾았다면 더이상 탐색할 필요 없기 때문에 return.
    //     }
    // }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // @Test
    // map<vector<int>, int> testM;
    // vector<int> testV = {2, 3};
    // testM[testV] = 97;
    // cout << testM[{2, 3}] << '\n';
    
    vector<vector<int>> answer;
    for(int i = 0; i < nodeinfo.size(); i++) {
        m[nodeinfo[i]] = i + 1;
        m2[i+1] = nodeinfo[i];
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    int root = m[nodeinfo[0]];
    
    // lc, rc 갱신하는 로직
    go(root, 0, 0, 100001, nodeinfo);
    
    preOrder(root);
    postOrder(root);
    
    answer.push_back(v1);
    answer.push_back(v2);
    
    return answer;
}