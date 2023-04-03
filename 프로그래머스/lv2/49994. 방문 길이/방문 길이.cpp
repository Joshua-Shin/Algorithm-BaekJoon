#include <bits/stdc++.h>
using namespace std;
// RULD
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int solution(string dirs) {
    int answer = 0;
    map<char, int> k;
    k['R'] = 0; k['U'] = 1; k['L'] = 2; k['D'] = 3;
    // 한번 이동한 경로는 카운트 안한다.
    // 이동한 경로를 map<string, int> m 에 담으면 되겠네
    // ex) (-1, 3) -> (-1, 2) => m["-13-1-2"]++; m["-12-13"]++;
    map<string, int> m;
    int x = 0, y = 0;
    for(auto d: dirs) {
        int nx = x + dx[k[d]];
        int ny = y + dy[k[d]];
        if(!(-5 <= nx && nx <= 5 && -5 <= ny && ny <= 5)) continue;
        string str = to_string(x) + to_string(y) + to_string(nx) + to_string(ny);
        string str2 = to_string(nx) + to_string(ny) + to_string(x) + to_string(y);
        x = nx; y = ny;
        if(m[str]==1) continue; 
        m[str]++; m[str2]++;
        answer++;
    }
    return answer;
}