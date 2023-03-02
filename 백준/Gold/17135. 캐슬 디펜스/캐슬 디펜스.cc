#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int dist[16][16];
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
// 한턴 끝나고 적 전체 움직이기
void moveBoard(vector<vector<int>> &board) {
    for(int i = board.size()-1; i > 0; i--)
        for(int j = 0; j < board[0].size(); j++) 
            swap(board[i][j], board[i-1][j]);
    for(int j = 0; j < board[0].size(); j++)
        board[0][j] = 0;
}
// 궁수의 현 위치에서 맞출 수 있는 가장 가까이에 있는 적의 좌표 반환
pair<int, int> findEnemy(vector<vector<int>> &board, int y) {
    memset(dist, -1, sizeof(dist));
    vector<vector<int>> candidate;
    queue<pair<int, int>> q;
    int x = n -1;
    if(board[x][y]) return {x, y};
    dist[x][y] = 1;
    q.push({x, y});
    while(!q.empty()) {
        tie(x, y) = q.front();
        if(dist[x][y] > d) break;
        if(board[x][y]) candidate.push_back({dist[x][y], y, x});
        q.pop();
        for(int k = 0; k < 3; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if(!candidate.size()) return {-1, -1};
    sort(candidate.begin(), candidate.end()); // 가장 가깝고, 가장 왼쪽에 있는 애로 정렬
    return {candidate[0][2], candidate[0][1]};
}
// 제거할 적 명수 반환
int simulate(vector<vector<int>> board, vector<int> sel) {
    int ret = 0;
    int n = ::n;
    while(n--) {
        vector<pair<int, int>> enemy;
        for(int i = 0; i<sel.size(); i++) {
            if(!sel[i]) continue;
            auto[x, y] = findEnemy(board, i);
            if(x == -1) continue;
            // if(!board[x][y]) continue;
            enemy.push_back({x, y});
            // board[x][y] = 0;
            // ret++;
        }
        sort(enemy.begin(), enemy.end());
        enemy.erase(unique(enemy.begin(), enemy.end()), enemy.end());
        ret += enemy.size();
        for(auto [a, b] : enemy) board[a][b] = 0;
        moveBoard(board);
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> d;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];
    // 궁수 3명 배치 조합
    vector<int> sel(m, 0);
    for(int i = m - 3; i < m; i++)
        sel[i] = 1;
    // test
    // for(auto x: sel) cout << x << ' ';
    int answer = 0;
    do {
        // int result = simulate(board, sel);
        // if(answer < result) {
        //     answer = result;
        //     for(auto x: sel) cout << x << ' ';
        //     cout << '\n';
        // }
        answer = max(answer, simulate(board, sel));
    } while (next_permutation(sel.begin(), sel.end()));
    cout << answer;   
}