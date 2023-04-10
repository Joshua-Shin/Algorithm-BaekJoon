#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>> v;
ll idx[4] = {(ll)1e9, (ll)1e9, (ll)1e9, (ll)1e9};
void findPoints(vector<int> l1, vector<int> l2) {
    int a, b, c, d, e, f;
    a = l1[0]; b = l1[1]; e = l1[2];
    c = l2[0]; d = l2[1]; f = l2[2];
    ll cal1 = (ll)a * d - (ll)b * c;
    if(cal1 == 0) return;
    ll cal2 = (ll)b * f - (ll)e * d;
    ll cal3 = (ll)e * c - (ll)a * f;
    // 둘중 하나라도 딱 나누어 떨어지지 않으면 리턴.
    if((ll)cal2 % cal1 != 0 || (ll)cal3 % cal1 != 0) return;
    v.push_back({(ll)cal2 / cal1, (ll)cal3 /cal1});
    return; 
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    for(int i = 0; i< line.size()-1; i++) {
        for(int j = i + 1; j <line.size(); j++) {
            findPoints(line[i], line[j]);
        }
    }
    // cout << v.size() << '\n';

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // cout << v.size() << '\n';
    
    // for(auto e: v) {
        // cout << e.first << ' ' << e.second << '\n';
    // }


    for(auto e: v) {
        if(idx[0] == 1e9 || idx[0] < e.first) idx[0] = e.first;
        if(idx[2] == 1e9 || idx[2] > e.first) idx[2] = e.first;
        if(idx[1] == 1e9 || idx[1] < e.second) idx[1] = e.second;
        if(idx[3] == 1e9 || idx[3] > e.second) idx[3] = e.second;
    }
    // for(int i = 0; i < 4; i++) {
    //     cout << idx[i] << ' ';
    // }
    // cout << '\n';
    for(ll y = idx[1]; y >= idx[3]; y--) {
        string temp="";
        for(ll x = idx[2]; x <= idx[0]; x++) {
            bool flag = false;
            for(ll k = 0; k < v.size(); k++) {
                if((ll)x == v[k].first && (ll)y == v[k].second) {
                    flag = true;
                    break;
                }
            }
            if(flag) temp += '*';
            else temp += '.';
        }
        answer.push_back(temp);
    }
    return answer;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // vector<vector<int>> line = {{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    vector<vector<int>> line = {{0, 1, -1}, {1, 0, -1}, {1, 0, 1}};
    auto ans = solution(line);
    for(auto x: ans) cout << x << '\n';
}