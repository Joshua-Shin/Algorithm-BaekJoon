#include <bits/stdc++.h>
using namespace std;
int d[200][200];
int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxAlp = 0, maxCop = 0;
    for(auto pro: problems) {
        maxAlp = max(maxAlp, pro[0]);
        maxCop = max(maxCop, pro[1]);
    }
    if(alp >= maxAlp && cop >= maxCop) return 0;
    for(int i = 0; i <= maxAlp; i++) {
        for(int j = 0; j <= maxCop; j++) {
            d[i][j] = 1e9;
        }
    }
    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);
    d[alp][cop] = 0;

    for(int i = alp; i <= maxAlp; i++) {
        for(int j = cop; j <= maxCop; j++) {
            d[i][j + 1] = min(d[i][j + 1], d[i][j] + 1);
            d[i+1][j] = min(d[i+1][j], d[i][j] + 1);
            for(int k = 0; k < problems.size(); k++) {
                if(problems[k][0] > i || problems[k][1] > j) continue;
                d[min(i + problems[k][2], maxAlp)][min(j + problems[k][3], maxCop)] 
                    = min(d[min(i + problems[k][2], maxAlp)][min(j + problems[k][3], maxCop)], d[i][j] + problems[k][4]);
            }
        }
    }
    return d[maxAlp][maxCop];
}