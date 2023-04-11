#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    int cur1 = deliveries.size()-1;
    int cur2 = pickups.size()-1;
    while(1) {
        if(cur1 >= 0 && deliveries[cur1] == 0) cur1--;
        else break;
    }
    while(1) {
        if(cur2 >= 0 && pickups[cur2] == 0) cur2--;
        else break;
    }
    while(1) {
        if(cur1 == -1 && cur2 == -1) break;
        answer += (ll)(max(cur1, cur2) + 1) * 2;
        int box = cap;
        for( ; cur1 >= 0; cur1--) {
            if(deliveries[cur1]==0) continue;

            if(deliveries[cur1] > box) {
                deliveries[cur1] -= box;
                break;
            } else if(deliveries[cur1] == box) {
                deliveries[cur1] = 0;
                cur1--;
                while(1) {
                    if(cur1 >= 0 && deliveries[cur1] == 0) cur1--;
                    else break;
                }
                break;
            } else { // deliveries[cur1] < box
                box -= deliveries[cur1];
                deliveries[cur1] = 0;
            }
        }
        box = cap;
        for( ; cur2 >= 0; cur2--) {
            if(pickups[cur2]==0) continue;
            if(pickups[cur2] > box) {
                pickups[cur2] -= box;
                break;
            } else if(pickups[cur2] == box) {
                pickups[cur2] = 0;
                cur2--;
                while(1) {
                    if(cur2 >= 0 && pickups[cur2] == 0) cur2--;
                    else break;
                }
                break;
            } else {
                box -= pickups[cur2];
                pickups[cur2] = 0;
            }
        }
    }
    return answer;
}