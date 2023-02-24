#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int dfs(int i, int j, vector<vector<int>>& board) {
    if(i == 0 || j == 0) return board[i][j]; // board의 가장자리인 경우 현재 칸 값 반환
    
    if(dp[i][j] != -1) return dp[i][j]; // memoization
    
    int result = 0;
    if(board[i][j] == 1) { // 현재 칸 값이 1인 경우
        result = min({dfs(i-1, j-1, board), dfs(i-1, j, board), dfs(i, j-1, board)}) + 1;
        // 왼쪽 위, 위쪽, 왼쪽 대각선 방향의 칸 중 가장 작은 값에 1을 더한 값이 현재 칸까지 이어지는 가장 큰 정사각형의 한 변의 길이
    }
    dp[i][j] = result; // memoization
    return result;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    
    fill(&dp[0][0], &dp[1000][1001], -1); // dp 배열 -1로 초기화
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            answer = max(answer, dfs(i, j, board));
            // dfs를 통해 각 칸에서 이어지는 가장 큰 정사각형의 한 변의 길이를 구하고, 그 중 가장 큰 값을 answer에 저장
        }
    }
    
    return answer * answer; // 가장 큰 정사각형의 넓이 반환
}
