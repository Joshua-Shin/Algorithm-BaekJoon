#include <bits/stdc++.h>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
bool check[101][101];
int bfs(int x, int y, int n, int m, vector<vector<int>> &picture) {
    int num = picture[x][y];
    int area = 0;
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        area++;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(check[nx][ny]) continue;
            if(picture[nx][ny] != num) continue;
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return area;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    swap(m, n);
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int area = 0;
    memset(check, false, sizeof(check));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(picture[i][j] == 0) continue;
            if(check[i][j]) continue;
            area = bfs(i, j, n, m, picture);
            number_of_area++;
            max_size_of_one_area = max(max_size_of_one_area, area);
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}