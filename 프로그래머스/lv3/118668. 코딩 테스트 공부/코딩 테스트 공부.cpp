#include <bits/stdc++.h>
using namespace std;
int solution(int alp, int cop, vector<vector<int>> problems) {
    int ma = 0, mc = 0;
    for(auto p: problems) {
        ma = max(ma, p[0]);
        mc = max(mc, p[1]);
    }
    if(alp >= ma && cop >= mc) return 0;
    alp = min(alp, ma);
    cop = min(cop, mc);
    int d[ma+1][mc+1];
    for(int i = 0; i <= ma; i++) {
        for(int j = 0; j <= mc; j++) {
            d[i][j] = 1e9;
        }
    }
    d[alp][cop] = 0;
    for(int i = alp; i <= ma; i++) {
        for(int j = cop; j <= mc; j++) {
            if(i+1 <= ma) d[i+1][j] = min(d[i+1][j], d[i][j] + 1);
            if(j+1 <= mc) d[i][j+1] = min(d[i][j+1], d[i][j] + 1);
            for(auto p: problems) {
                if(i < p[0] || j < p[1]) continue;
                d[min(i+p[2], ma)][min(j+p[3], mc)] = min(d[min(i+p[2], ma)][min(j+p[3], mc)], d[i][j] + p[4]);
            }
        }
    }
    return d[ma][mc];
}