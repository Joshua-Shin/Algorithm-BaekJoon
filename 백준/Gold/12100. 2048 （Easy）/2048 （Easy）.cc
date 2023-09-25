#include <bits/stdc++.h>
using namespace std;
int n;
int answer;
bool check[21][21];
vector<vector<int>> move(int dir, vector<vector<int>> ret) {
    if(dir==0) { // 오른쪽으로 이동
        for (int j = n-2; j >=0; j--) {
            for (int i = 0; i < n; i++) {
                if(ret[i][j]) {
                    int k = 1;
                    while(j+k < n) {
                        if(ret[i][j+k]==0) k++;
                        else break;
                    }
                    if(j+k==n) swap(ret[i][j], ret[i][n-1]);
                    else {
                        if(ret[i][j] == ret[i][j+k] && check[i][j+k]==false) {
                            ret[i][j] = 0;
                            ret[i][j+k] *=2;
                            check[i][j+k] = true;
                        }
                        else swap(ret[i][j], ret[i][j+k-1]);
                    }
                }
            }
        }  
    }
    else if(dir ==1) { // 위로// 다시
        for (int i =1; i <n; i++) {
            for (int j = 0; j <n; j++) {
                if(ret[i][j]) {
                    int k = 1;
                    while(i-k >= 0) {
                        if(ret[i-k][j]==0) k++;
                        else break;
                    }
                    if(i-k==-1) swap(ret[i][j], ret[0][j]);
                    else {
                        if(ret[i][j] == ret[i-k][j] && check[i-k][j]==false) {
                            ret[i][j] = 0;
                            ret[i-k][j] *=2;
                            check[i-k][j] = true;
                        }
                        else swap(ret[i][j], ret[i-k+1][j]);
                    }
                }
            }
        }
    }
    else if(dir == 2) { // 왼쪽
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if(ret[i][j]) {
                    int k = 1;
                    while(j-k >= 0) {
                        if(ret[i][j-k]==0) k++;
                        else break;
                    }
                    if(j-k==-1) swap(ret[i][j], ret[i][0]);
                    else {
                        if(ret[i][j] == ret[i][j-k] && check[i][j-k] ==false) {
                            ret[i][j] = 0;
                            ret[i][j-k] *=2;
                            check[i][j-k] = true;
                        }
                        else swap(ret[i][j], ret[i][j-k+1]);
                    }
                }
            }
        }
    }
    else if(dir ==3) { // 아래
        for (int i =n-2; i >=0; i--) {
            for (int j = 0; j <n; j++) {
                if(ret[i][j]) {
                    int k = 1;
                    while(i+k < n) {
                        if(ret[i+k][j]==0) k++;
                        else break;
                    }
                    if(i+k==n) swap(ret[i][j], ret[n-1][j]);
                    else {
                        if(ret[i][j] == ret[i+k][j] && check[i+k][j] == false) {
                            ret[i][j] = 0;
                            ret[i+k][j] *=2;
                            check[i+k][j] = true;
                        }
                        else swap(ret[i][j], ret[i+k-1][j]);
                    }
                }
            }
        }
    }
    return ret;
}
void go(int cnt, vector<vector<int>> board) {
    if(cnt==5) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                answer = max(answer, board[i][j]);
        return;
    }
    vector<vector<int>> convertedBoard[4];
    for(int k = 0 ; k<4; k++) {
        memset(check, false, sizeof(check));
        convertedBoard[k] = move(k, board);
        go(cnt +1, convertedBoard[k]);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    go(0, board);
    cout << answer << '\n';
    return 0;
}