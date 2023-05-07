#include <bits/stdc++.h>
using namespace std;
int n, m;
tuple<int, int, int> edge[100005];

// 유니온 파인드 예시
// 정점의 개수가 1번부터 10번인 부모테이블.
vector<int> parent(10001);
// getParent(x) : x 값을 받았을때, 부모 정점을 반환
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
// unionParent(x, y) : x와 y의 부모 정점을 합쳐라 = 정점 x와 y를 같은 그룹으로 묶으라
void unionParent(int x, int y) {
    x = getParent(x);
    y = getParent(y);
    if (x < y) parent[y] = x;
    else parent[x] = y;
}
// isSameParent(x, y) : x와 y가 같은 부모를 갖고 있는지 확인.
bool isSameParent(int x, int y) {
    return getParent(x) == getParent(y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};

    }
    sort(edge, edge + m);

    // 여기 아래는 메인함수안에
    // 부모값을 자기 자신으로 잡아주는 초기화 과정
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int cnt = 0, answer = 0;
    for(int i = 0; i< m ; i++) {
        if(isSameParent(get<1>(edge[i]), get<2>(edge[i]))) continue;
        answer += get<0>(edge[i]);
        unionParent(get<1>(edge[i]), get<2>(edge[i]));
        if(++cnt == n-1) break;
    }
    cout << answer << '\n';

    return 0;
}
