#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &key) {
    vector<vector<int>> copyKey = key;
    for(int i = 0; i < key.size(); i++) {
        for(int j = 0; j < key.size(); j++) {
            key[j][key.size()-1-i] = copyKey[i][j];
        }
    }
    return;
}
bool isMatch2(int x, int y, vector<vector<int>> &key, vector<vector<int>> lock) {
    for(int i = 0; i < key.size(); i++) {
        for(int j = 0; j < key.size(); j++) {
            if(x + i >= lock.size() || y + j >= lock.size() || x + i < 0 || y + j < 0) continue;
            if(key[i][j]==1) {
                if(lock[x + i][y + j] == 1) return false;
                else lock[x + i][y + j] = 1;
            } else {
                if(lock[x + i][y + j] == 0) return false;
            }
        }
    }
    for(int i = 0; i < lock.size(); i++) {
        for(int j = 0; j < lock.size(); j++) {
            if(lock[i][j] == 0) return false;
        }
    }
    return true;
}
bool isMatch(vector<vector<int>> &key, vector<vector<int>> &lock) {
    int st = -((int)key.size()-1);
    int en = lock.size();
    // cout << st << ' ' << en << '\n';
    for(int i = st; i < en; i++) { // 이게 왜 실행이 안돼???!?!?!?!?
        for(int j = st; j < en; j++) {
            if(isMatch2(i, j, key, lock)) return true;
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int k = 0; k < 4; k++) {
        rotate(key);
        if(isMatch(key, lock)) return true;
    }
    return false;
}