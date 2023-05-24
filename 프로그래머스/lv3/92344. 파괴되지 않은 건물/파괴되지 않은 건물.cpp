#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> v(n+1, vector<int>(m+1, 0));

    for(auto e: skill) { // 250,000
        int type = e[0], r1 = e[1], c1 = e[2], r2 = e[3], c2 = e[4], degree = e[5];
        if(type == 1) { // attack
            v[r1][c1] -= degree;
            v[r2 + 1][c1] += degree;
            v[r1][c2 + 1] += degree;
            v[r2 + 1][c2 + 1] -= degree;
        } else {
            v[r1][c1] += degree;
            v[r2 + 1][c1] -= degree;
            v[r1][c2 + 1] -= degree;
            v[r2 + 1][c2 + 1] += degree;
        }
    }
    
    // int printNum = 0;
    // // printForTest
    // cout << "printNum: " << printNum++ << '\n';
    // for(int i = 0; i < v.size(); i++) {
    //     for(int j = 0; j < v[0].size(); j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    

    // // printForTest
    // cout << "printNum: " << printNum++ << '\n';
    // for(int i = 0; i < v.size(); i++) {
    //     for(int j = 0; j < v[0].size(); j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // left To right
    for(int i = 0; i < v.size(); i++) {
        for(int j = 1; j < v[0].size(); j++) {
            v[i][j] += v[i][j-1];
        }
    }

    // top To bottom
    for(int j = 0; j < v[0].size(); j++) {
        for(int i = 1; i < v.size(); i++) {
            v[i][j] += v[i-1][j];
        }
    }


    // // printForTest
    // // cout << "printNum: " << printNum++ << '\n';
    // for(int i = 0; i < v.size(); i++) {
    //     for(int j = 0; j < v[0].size(); j++) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] += v[i][j];
            if(board[i][j] > 0) answer++;
        }
    }
    return answer;
}